/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:51:59 by rnabil            #+#    #+#             */
/*   Updated: 2022/08/15 20:52:07 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex_bonus.h"

/*executes command and stores result in fd_out*/
static void	execute_child(char *cmd, char **envp, int fd_in, int fd_out)
{
	pid_t	pid;
	char	*path;
	char	**cmd_args;

	if (fd_in < 0)
		return ;
	pid = fork();
	if (pid == -1)
		fatal_error("failed to create a child process!");
	if (pid == 0)
	{
		cmd_args = ft_split(cmd, ' ');
		path = get_path(cmd_args[0], path_env(envp));
		dup2(fd_out, 1);
		close (fd_out);
		execve(path, cmd_args, envp);
	}
}

/*opens infile and outfile*/
/*if there is an error opening infile an error is stored in stderr*/
static void	files_init(char	*infile, char *outfile, int	*file, int append)
{

	file[0] = open (infile, O_RDONLY);
	//when there is an error opening infile, it reads from std_in
	if (file[0] == -1)
		error (error_message("no such file or directory: ", infile));
	else
	{
		dup2(file[0], 0);
		close(file[0]);
	}
	if (append)
		file[1] = open (outfile, O_RDWR | O_CREAT | O_APPEND, 0777);
	else
		file[1] = open (outfile, O_RDWR | O_CREAT | O_TRUNC, 0777);
}

/*Main code, executes major instructions*/
static void	pipex_bonus(int argc, char **argv, char **envp)
{
	int	pipe_fd[2];
	int	file[2];
	int	i;
	int	append;

	//heredoc and append part, if there is a heredoc append = 1 else append = 0
	check_heredoc(argv, &i, &append);
	//small parsing
	if (append)
		parsing(argc, argv, envp, 3);
	else
		parsing(argc, argv, envp, 2);
	//files opening 
	files_init(argv[1], argv[argc - 1], file, append);
	while (i <= argc - 2)
	{
		if (pipe(pipe_fd) == -1)
			fatal_error("failed to create pipe!\n");
		if (i == argc - 2)
		{
			if (file[1] == -1)
				fatal_error(error_message("could not create file: ", argv[argc - 1]));
			else
				execute_child(argv[i], envp, pipe_fd[0], file[1]);
		}
		else
		{
			if (!append && i == 2)
				execute_child(argv[i], envp, file[0], pipe_fd[1]);
			if (!append && i > 2)
				execute_child(argv[i], envp, pipe_fd[0], pipe_fd[1]);
		}
		dup2(pipe_fd[0], 0);
		close (pipe_fd[0]);
		close (pipe_fd[1]);
		i++;
	}
	close (file[1]);
	while(wait(NULL) > 0);
}

int	main(int argc, char *argv[], char **envp)
{
	if (argc >= 5)
		pipex_bonus(argc, argv, envp);
	else
		error("Invalid arguments!");
	return (0);
}
