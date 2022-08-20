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

/*Executes the first command and sends the result to the input side of pipe*/
static void	first_part(char *cmd, char *option, char **envp)
{
	char	*path;
	char	*options;

	options = (char **)malloc(sizeof(char *) * 3);
	options[0] = ft_strdup(cmd);
	options[1] = ft_stdup(option);
	options[3] = NULL;
	//Do I really need a third option?
	path = get_command_path(cmd);
	execve(path, options, envp);
	//how can I free options before executing execve? 
}

/*Takes the input from the output side of the pipe and executes the 2nd cmd*/
static void	second_part()
{

}

/*Main code, executes major instructions*/
int	main(int argc, char *argv[], char **envp)
{
	char 	*options[] = {"ls", NULL};
	char	*path;
	int		pipe_fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		pid = fork();
		if (pid == -1)
			error("Forking error occured!");
		if (pid == 0)
		{
			/*Here we execute the first part and store the output in the pipe*/
			first_part(argv[1], argv[2], envp);
			if(pipe(pipe_fd) == -1)
				error("Pipe creating error occured!");
		}
		else
		{
			/*This is the parent's part, it needs to wait for the child to finish and then execute the second part*/
			/*I need to wait for the child processes before executing the second part*/
			ft_printf("This is the parent whose pid : %d talking!\n", (int)pid);
			/*Wait for the first process*/
			second_part();
		}
	}
	else
		error("Invalid arguments!");
	/*Wait for the second process*/
	return (0);
}

/*
pipe()
  |
  +--- fork()
         |
         +--- child1 [cmd1]
         |      +-- dup2(fd_infile, STDIN))
         |      +-- dup2(pipe[1], STDOUT)
         |      +-- close(pipe[0])
         |      +-- close(pipe[1])
         |      +-- ft_split the command options
         |          and find the correct path
         |      +-- execve(cmd1_path, options, envp)
         |
         +--- child2 [cmd2]
         |      +-- dup2(pipe[0], STDIN)
         |      +-- dup2(fd_outfile, STDOUT)
         |      +-- close(pipe[0])
         |      +-- close(pipe[1])
         |      +-- ft_split the command options
         |          and find the correct path
         |      +-- execve(cmd2_path, options, envp)
         |
         +--- parent
                +-- close(pipe[0])
                +-- close(pipe[1])
                +-- close(fd_infile)
                +-- close(fd_outfile)
                +-- waitpid(pid1, status, 0)
                +-- waitpid(pid2, status, 0)
*/