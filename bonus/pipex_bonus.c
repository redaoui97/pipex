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

static void	execute_child(char **argv, char **envp, int fd_in, int ft_out)
{
	pid_t	pid;
	char	*path;
	char	**cmd_args;
	pid = fork();
	if (pid == -1)
		fatal_error("failed to create a child process!");
	if (pid == 0)
	{
		cmd_args = ft_split(argv[2], ' ');
		path = get_path(cmd_args[0], path_env(envp));
		dup2(fd_in, 0);
		dup2(fd_out, 1);
		close (fd_int);
		close (fd_out);
		execve(path, cmd_args, envp);
	}
}

/*Main code, executes major instructions*/
static void	pipex_bonus(int argc, char **argv, char **envp)
{
	int	pipe_fd[2];
	int	i;
	int	infile;
	int	outfile;

	//I can make an array for intfile and outfile to save line code
	infile = open (argv[1], O_RDONLY);
	if (infile == -1)
		error (error_message("no such file or directory: ", argv[1]));
	else
		dup2(infile, 0);
	close (infile);
	i = 3;
	while (i < argc - 2)
	{
		if (pipe(pipe_fd) == -1)
			fatal_error("failed to create pipe!\n");
		execute_child(0, pipe_fd[1]);
		close (pipe_fd[1]);
		dup2(pipe_fd[0], 0);
		close (pipe_fd[0]);
		i++;
	}
	//execute last command and redirect output to outfile
	while(wait(NULL) > 0);//waits for all child processes to finish
}

int	main(int argc, char *argv[], char **envp)
{
	if (argc >= 5)
		pipex_bonus(argc, argv, envp);
	else
		error("Invalid arguments!");
	return (0);
}
