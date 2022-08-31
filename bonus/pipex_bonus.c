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

static void	heredoc_part(int argc, char **argv, char **envp, int *heredoc)
{
	char	*line;

	parsing(argc, argv, envp, 4);
	if (pipe(heredoc) == -1)
		fatal_error("failed to create pipe\n");
	line = get_next_line(0);
	while (line)
	{
		if (!ft_strncmp(line, argv[2], ft_strlen(argv[2])))
			break ;
		write (heredoc[1], line, ft_strlen(line));
		free (line);
		line = get_next_line(0);
	}
	if (line)
		free (line);
	close (heredoc[1]);
}

void	close_fd(int *pipe_fd, int heredoc)
{
	dup2(pipe_fd[0], 0);
	close (heredoc);
	close (pipe_fd[0]);
	close (pipe_fd[1]);
}

/*Main code, executes major instructions*/
static void	pipex_bonus(int argc, char **argv, char **envp)
{
	int	pipe_fd[2];
	int	heredoc[2];
	int	file[2];
	int	i;
	int	append;

	check_heredoc(argv, &i, &append);
	if (append)
		heredoc_part(argc, argv, envp, heredoc);
	else
		parsing(argc, argv, envp, 2);
	file[0] = heredoc[0];
	files_init(argv[1], argv[argc - 1], file, append);
	while (i <= argc - 2)
	{
		if (pipe(pipe_fd) == -1)
			fatal_error("failed to create pipe!\n");
		if (i == argc - 2)
		{
			if (file[1] == -1)
				fatal_error(error_message("can't create :", argv[argc - 1]));
			else
				execute_child(argv[i], envp, pipe_fd[0], file[1]);
		}
		if (append && i == 3)
			execute_child(argv[i], envp, heredoc[0], pipe_fd[1]);
		if (!append && i == 2)
			execute_child(argv[i], envp, file[0], pipe_fd[1]);
		if (!append && i > 2 && i < (argc - 2))
			execute_child(argv[i], envp, pipe_fd[0], pipe_fd[1]);
		close_fd(pipe_fd, heredoc[1]);
		i++;
	}
	close (file[1]);
	while (wait (NULL) > 0);
}

int	main(int argc, char *argv[], char **envp)
{
	if (argc >= 5)
		pipex_bonus(argc, argv, envp);
	else
		error("Invalid arguments!");
	return (0);
}
