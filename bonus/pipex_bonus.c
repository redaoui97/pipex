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

static void	execute_child(char *cmd, char **envp, int fd_out)
{
	pid_t	pid;
	char	*path;
	char	**cmd_args;

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

static void	check_heredoc(int argc, char **argv, int *first_cmd, int *append)
{
	int	here_doc_pipe[2];

	if (ft_strncmp("here_doc", argv[1], 8))
	{
		first_cmd = 3;
	}
	else
	{
		first_cmd = 2;
		append = 1;
	}
}

static void	files_init(char	*infile, char *outfile, int	*file, int append)
{

	file[0] = open (infile, O_RDONLY);
	if (file[0] == -1)
	{
		dup2(-1, 0);
		error (error_message("no such file or directory: ", infile));
	}
		dup2(file[0], 0);
		close(file[0]);
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

	parsing(argv, envp);//I still have to do some parsing
	//heredoc and append part, if there is a heredoc append = 1 else append = 0
	check_heredoc(argc, argv, &i, &append);
	files_init(argv[1], argv[argc - 1], file, append);
	if (file[0] == -1)
		i++;
	while (i <= argc - 2)
	{
		if (pipe(pipe_fd) == -1)
			fatal_error("failed to create pipe!\n");
		if (i == argc - 2)
		{
			if (file[1] == -1)
				fatal_error(error_message("no such file or directory: ", argv[argc - 1]));
			execute_child(argv[i], envp, file[1]);
		}
		else
			execute_child(argv[i], envp, pipe_fd[1]);
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
