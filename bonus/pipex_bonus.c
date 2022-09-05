/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:51:59 by rnabil            #+#    #+#             */
/*   Updated: 2022/09/05 14:11:05 by rnabil           ###   ########.fr       */
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
		close (fd_in);
		execve(path, cmd_args, envp);
	}
}

/*checks if there is a heredoc*/
static void	heredoc_part(int argc, char **argv, char **envp, int *heredoc)
{
	char	*line;

	//Maybe I have to assign heredoc array to each heredoc fd
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

/*executes in each loop iteration inside the main function*/
void	iteration(t_data data, int *i, int *file, int *pipe_fd)
{
	int		argc;
	char	**argv;
	char	**envp;

	argc = data.argc;
	argv = data.argv;
	envp = data.envp;
	if (*i == argc - 2)
	{
		if (data.append)
			file[1] = open (data.outfile, O_RDWR | O_CREAT | O_APPEND, 0777);
		else
			file[1] = open (data.outfile, O_RDWR | O_CREAT | O_TRUNC, 0777);
		if (file[1] == -1)
			fatal_error(error_message("can't create :", argv[argc - 1]));
		else
			execute_child(argv[*i], envp, pipe_fd[0], file[1]);
	}
	if (!(data.append) && *i == 2)
		execute_child(argv[*i], envp, file[0], pipe_fd[1]);
	if (!(data.append) && *i > 2 && *i < (argc - 2))
		execute_child(argv[*i], envp, pipe_fd[0], pipe_fd[1]);
}

/*Main code, executes major instructions*/
static void	pipex_bonus(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	int		file[2];
	int		heredoc[2];
	int		i;
	t_data	data;

	set_data(&data, argc, argv, envp);
	i = data.first_command;
	if (data.append)
		heredoc_part(argc, argv, envp, heredoc);
	else
		parsing(argc, argv, envp, 2);
	files_init(argv[1], file, data.append);
	while (i <= argc - 2)
	{
		if (pipe(pipe_fd) == -1)
			fatal_error("failed to create pipe!\n");
		if (data.append && i == 3)
			execute_child(argv[i], envp, heredoc[0], pipe_fd[1]);
		iteration(data, &i, file, pipe_fd);
		close_fd(pipe_fd, heredoc[1]);
		i++;
	}
	close_n_wait(file[1]);
}
//close outfile fd and fd 4
/*simply executes pipex function*/
int	main(int argc, char *argv[], char **envp)
{
	if (argc >= 5)
		pipex_bonus(argc, argv, envp);
	else
		error("Invalid arguments!");
	return (0);
}
