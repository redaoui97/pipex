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

static *int	execute_command(char *arg, char **envp, int *pipe_fd, int out)
{
	char	**cmd_args;
	char	*path;
	int		pipe_fd2[2];
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		fatal_error("failed to create a child process!\n");
	if (pid == 0)
	{
		cmd_args = ft_split(arg, ' ');
		path = get_path(cmd_args[0], path_env(envp));
		if (pipe(pipe_fd2) == -1)
			fatal_error("failed to open a pipe!\n");
		dup2(pipe_fd[0], 0);
		if (!out)
			dup2(pipe_fd2[1], 1);
		else
			dup2(out, 1);
		close (pipe_fd[0]);
		close (pipe_fd[1]);
		close (pipe_fd2[1]);
		execve(path, cmd_args, envp);
	} 
}

/*Main code, executes major instructions*/
static void	pipex_bonus(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	int		pipe_fd_copy[2];
	int		infile_fd;
	int		outfile_fd;

	infile_fd = open(argv[1], O_RDONLY);
	outfile_fd = open (argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
	//redirects the infile into stdin
	if (infile_fd == -1)
		fatal_error(error_message("no such file or directory: ", argv[1]));
	if (pipe(pipe_fd) == -1)
		error("failed to open a pipe\n");
	if (pipe(pipe_fd_copy) == -1)
		error("failed to open a pipe\n");
	//starts looping through cmds and executing them
	//First iteration takes infile as input
	//what if the infile returns -1
	dup2(pipe_fd[0], infile_fd);
	close(pipe_fd[0]);
	i = 3;
	while (i < argc - 1)
	{
		pipe_fd_copy[0] = pipe_fd[0];
		pipe_fd_copy[1] = pipe_fd[1];
		if (i == argc - 2 && outfile != -1)
			execute_command(argc[i], envp, &pipe_fd, outfile_fd);
		else
			execute_command(argc[i], envp, &pipe_fd, 0);
		close (pipe_fd_copy[0]);
		close (pipe_fd_copy[1]);

		i++;
	}
	if (outfile_fd == -1)
		error(error_message("no such file or directory: ", argv[argc - 1]));
	close (pipe_fd[0]);
	close (pipe_fd[1]);
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
