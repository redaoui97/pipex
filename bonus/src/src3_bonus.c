/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src3_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 12:54:01 by rnabil            #+#    #+#             */
/*   Updated: 2022/09/06 10:58:45 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

/*************************  Functions collection 3 ****************************/

/*initializes data with args, used it just for norm*/
void	set_data(t_data *data, int argc, char **argv, char **envp)
{
	data->argc = argc;
	data->argv = argv;
	data->envp = envp;
	data->outfile = argv[argc - 1];
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		data->first_command = 3;
		data->append = 1;
	}
	else
	{
		data->first_command = 2;
		data->append = 0;
	}
}

/*simply closes the fd from parameters*/
void	close_fd(int *pipe_fd, int heredoc)
{
	dup2(pipe_fd[0], 0);
	close (heredoc);
	close (pipe_fd[0]);
	close (pipe_fd[1]);
}

/*closes file fd and waits for child processes to finish*/
void	close_n_wait(int file)
{
	int	wait_return;

	close(file);
	close (0);
	wait_return = wait (NULL);
	while (wait_return > 0)
		wait_return = wait(NULL);
}
