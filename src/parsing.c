/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:17:30 by rnabil            #+#    #+#             */
/*   Updated: 2022/08/21 15:17:41 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*checks if file exists in the current directory and can be read*/
static void	parse_infile(char *file)
{
	//if the infile doesn't exsist, an error message should be printed in stderr and the first command should be executed
	if (access(file, R_OK) == -1)
		error("file not found or cannot be read from!\n");
}

/*checks if file exists in the current directory and can be written into*/
static void	parse_outfile(char *file)
{
	//if the outfile doesn't exist, it should be created, incase of a creation error, an error message should be printed into stderr
	if (access(file, W_OK) == -1)//is this the correct path?
		error("file not found or cannot be written into!\n");
}

/*returns the PATH env variable from envp array*/
static char	*path_env(char **envp)
{
	//It returns the wrong path
	int		i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH", 4))
			return (ft_strdup(envp[i]));
		i++;
	}
	error ("PATH environment variable not found!");
	return (NULL);
}

/*gets the right path from a $PATH env*/
static char	*get_path(char *cmd, char *env_path)
{
	char	**paths;
	char	*path;
	int		i;

	paths = ft_split(env_path, ':');
	i = 0;
	path = ft_strdup("");
	while (paths[i] != NULL)
	{
		path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path, cmd);
		if (access(path, X_OK) == 0)
			return (path);
		i++;
	}
	error("command not found!\n");
	return (NULL);
}

/*Check if command and arguments are valid*/
static void	parse_command(char *command, char **envp)
{
	char	**command_args;
	char	*path;
	int		i;

	//I should instead of this check if the command exists and is executable, delete this
	//many leaks here
	if (ft_strlen(command) == 0)
		error ("empty command\n");
	command_args = ft_split(command, ' ');
	i = 0;
	path = get_path(command_args[0], path_env(envp));
	ft_printf("%s\n",path);
	if (!path)
		error ("Command not found!\n");
	pause();
	while (command_args[i])
	{
		i++;
	}
}

void	parsing(int argc, char **argv, char **envp)
{
	int	i;

	i = 2;
	/*
	if there is an error opening filein or executing the first command, an error message should be written into stderr
	*/
	parse_infile(argv[1]);//try this << eof| wc -l
	//parse_outfile(argv[argc - 1]);
	while (i < (argc - 1))
	{
		parse_command(argv[i], envp);
		i++;
	}
}

/*void function_dparsing_9dima()
{
	//2-parse first command and its parameters
		//split the string and get the command and it's parameters
		cmd_args = ft_split(argv[2], ' '); 
		//parse arguments
		check_arguments(cmd_args);
		//find the command from the envp $PATH variable 
		//real_path = get_path(cmd_args[0], path_env(envp));
		//put the command and parameters in the args array


	//3-part second command and its parameters
		//split the string and get the command and it's parameters 
		//find the command from the envp $PATH variable 
		//put the command and parameters in the args array
}*/