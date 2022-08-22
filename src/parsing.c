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

/*returns the PATH env variable from envp array*/
char	*path_env(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (strncmp(envp[i], "PATH", 4))
			return(ft_strdup(envp[i]));
		i++;
	}
	error ("PATH environment variable not found!");
}



/*gets the right path from a $PATH env*/
static char	get_path(char *cmd, char *env_path)
{
	char	**paths;
	char	*path;
	int		i;

	paths = ft_split(env_path, ':');
	i = 0;
	path = ft_strdup("");
	while (paths[i])
	{
		path = ft_strjoin(paths[i], '/');
		path = ft_strjoin(path, cmd);
		if (access(path, X_OK) == 0)
			return (path);
		i++;
	}
	error("command not found!");
	return (NULL);
}

int	parse_infile(char *file)
{
	//check if file exists in the current directory and can be accessed
	if (access(file, R_OK) == -1);
		error("file not found or cannot be read from!");
}

int	parse_outfile(char *file)
{
	//check if file exists in the current directory and can be accessed
	if (access(file, W_OK) == -1);//is this the correct path? 
		error("file not found or cannot be written into!");
}

/*Check if command and arguments are valid*/
/*hnaaaaaaaaaaaaaaaaa*/
void	parse_command(char *command)
void	check_arguments(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (i == 0)
			if (ft_strlen(args[i] > 15) || has_non_alpha(args[i]))
				error ("regular expression problem on the command!");
		else
		{
			if (args[i][0] != '-')
				error ("regular expression problem on command's parameters!");
		}
		i++;
	}
}
void	parsing(int argc, char **argv)
{
	int	i;

	i = 2;
	parse_infile(argv[1]);
	parse_outfile(argv[argc - 1]);
	while (i < (argc - 1))
	{
		parse_command(argv[i]);
		i++;
	}
}



void function_dparsing_9dima()
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
}