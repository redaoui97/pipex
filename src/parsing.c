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

/*checks if file exists in the current directory and can be read from*/
static void	parse_infile(char *file)
{
	char	*err;
	// I was writing error messages for unfound file
	if (access(file, R_OK) == -1)
		error("file not found or cannot be read from!\n");
}

/*checks if file exists in the current directory and can be written into*/
static void	parse_outfile(char *file)
{
	if (access(file, W_OK) == -1)//is this the correct path?
		error("file not found or cannot be written into!\n");
}

/*Check if command and arguments are valid*/
static void	parse_command(char *command, char **envp)
{
	char	**command_args;
	char	*path;
	char	*err;
	int		i;

	if (ft_strlen(command) == 0)
		error ("empty command\n");
	command_args = ft_split(command, ' ');
	i = 0;
	path = get_path(command_args[0], path_env(envp));
	if (!path)
	{
		err = ft_strdup("command not found: ");
		err = ft_strjoin(err, command_args[0]);
		err = ft_strjoin(err, "\n");
		error (err);
		free (err);
	}
	while (command_args[i])
		free (command_args[i++]);
	free (command_args);
	free (path);
}

void	parsing(int argc, char **argv, char **envp)
{
	parse_infile(argv[1]);//try this << eof| wc -l
	parse_command(argv[2], envp);
	parse_command(argv[3], envp);
	//parse_outfile(argv[4]);
}
