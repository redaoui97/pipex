/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:51:59 by rnabil            #+#    #+#             */
/*   Updated: 2022/08/15 20:52:07 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

/*Main code, executes major instructions*/
int	main(int argc, char *argv[], char **envp)
{
	char 	*options[] = {"ls", NULL};
	char	*path;
	pid_t	pid;

	ft_printf("Hello\n");
	pid = fork();
	//this part below is executed by both the child and the parent

	if (pid == -1)
		error("Error forking!");

	if (pid == 0)
	{
		execve("/bin/ls", options, envp);
	}
	else
	{
		ft_printf("This is the parent whose pid : %d talking!\n", (int)pid);
		usleep(10000000);
	}
	return (0);
}
