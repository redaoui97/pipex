/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:51:59 by rnabil            #+#    #+#             */
/*   Updated: 2022/09/11 09:48:40 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

/*Executes the first command and sends the result to the input side of pipe*/
static void	first_part(char **argv, char **envp, int *pipe_fd)
{
	char	*path;
	char	**cmd_args;
	char	*err;
	int		infile_fd;

	cmd_args = ft_split(argv[2], ' ');
	path = get_path(cmd_args[0], path_env(envp));
	infile_fd = open (argv[1], O_RDONLY);
	if (infile_fd == -1)
	{
		err = ft_strdup("no such file or directory: ");
		err = ft_strjoin(err, argv[1]);
		err = ft_strjoin(err, "\n");
		fatal_error(err);
	}
	dup2(infile_fd, 0);
	dup2(pipe_fd[1], 1);
	close (infile_fd);
	close (pipe_fd[0]);
	close (pipe_fd[1]);
	execve(path, cmd_args, envp);
}

/*Takes the input from the output side of the pipe and executes the 2nd cmd*/
static void	second_part(char **argv, char **envp, int *pipe_fd)
{
	char	*path;
	char	**cmd_args;
	int		outfile_fd;
	char	*err;

	cmd_args = ft_split(argv[3], ' ');
	path = get_path(cmd_args[0], path_env(envp));
	outfile_fd = open (argv[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (outfile_fd == -1 && ft_strlen(argv[3]) != 0 && ft_strlen(argv[2]))
	{
		err = ft_strdup("no such file or directory: ");
		err = ft_strjoin(err, argv[4]);
		err = ft_strjoin(err, "\n");
		fatal_error(err);
		free (err);
	}
	dup2(pipe_fd[0], 0);
	dup2(outfile_fd, 1);
	close (outfile_fd);
	close (pipe_fd[0]);
	execve(path, cmd_args, envp);
}

/*Main code, executes major instructions*/
static void	pipex(char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid;
	pid_t	pid2;

	parsing(argv, envp);
	if (pipe(pipe_fd) == -1)
		fatal_error("failed to open a pipe!\n");
	pid = fork();
	if (pid == -1)
		fatal_error("failed to create a child process!\n");
	if (pid == 0)
		first_part(argv, envp, pipe_fd);
	close (pipe_fd[1]);
	pid2 = fork();
	if (pid2 == -1)
		fatal_error("failed to create a child process!\n");
	if (pid2 == 0)
		second_part(argv, envp, pipe_fd);
	close (pipe_fd[0]);
	waitpid(pid, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	main(int argc, char *argv[], char **envp)
{
	if (argc == 5)
		pipex(argv, envp);
	else
		error("Invalid arguments!");
	return (0);
}
