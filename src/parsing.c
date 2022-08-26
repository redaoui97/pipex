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

/*was supposed to parse infile and outfile too but were handled in exec*/
void	parsing(char **argv, char **envp)
{
	parse_command(argv[2], envp);
	parse_command(argv[3], envp);
}
