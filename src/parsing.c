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
		error("file not found or cannot be read from!");
}

/*checks if file exists in the current directory and can be written into*/
static void	parse_outfile(char *file)
{
	//if the outfile doesn't exist, it should be created, incase of a creation error, an error message should be printed into stderr
	if (access(file, W_OK) == -1)//is this the correct path?
		error("file not found or cannot be written into!");
}

/*Check if command and arguments are valid*/
static void	parse_command(char *command)
{
	char	**command_args;
	int		i;

	//I should instead of this check if the command exists and is executable, delete this
	if (ft_strlen(command) == 0)
		error ("empty command");
	command_args = ft_split(command, ' ');
	i = 0;
	while (command_args[i])
	{
		if (i == 0)
		{
			if (ft_strlen(command_args[i]) > 15 || has_non_alpha(command_args[i]))
				return (free_words(command_args), error ("regular expression problem on the command!"));
		}
		i++;
	}
}

/*gets the right path from a $PATH env*/
char	*get_path(char *cmd, char *env_path)
{
	char	**paths;
	char	*path;
	int		i;

	paths = ft_split(env_path, ':');
	i = 0;
	path = ft_strdup("");
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path, cmd);
		if (access(path, X_OK) == 0)
			return (path);
		i++;
	}
	error("command not found!");
	return (NULL);
}

void	parsing(int argc, char **argv)
{
	int	i;

	i = 2;
	/*
	if there is an error opening filein or executing the first command, an error message should be written into stderr
	*/
	parse_infile(argv[1]);//try this << eof| wc -l
	// parse_outfile(argv[argc - 1]);
	// while (i < (argc - 1))
	// {
	// 	parse_command(argv[i]);
	// 	i++;
	// }
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