/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:02:30 by rnabil            #+#    #+#             */
/*   Updated: 2022/08/22 14:02:41 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

/*returns the PATH env variable from envp array*/
char	*path_env(char **envp)
{
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
char	*get_path(char *cmd, char *env_path)
{
	char	**paths;
	char	*path;
	int		i;

	paths = ft_split(env_path, ':');
	free (env_path);
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path, cmd);
		if (access(path, X_OK) == 0)
		{
			while (paths[++i])
				free (paths[i]);
			free (paths);
			return (path);
		}
		free (path);
		i++;
	}
	free (paths);
	return (NULL);
}

/*checks if there is a heredoc and sets values of first command & append*/
void	check_heredoc(char **argv, int *first_cmd, int *append)
{
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		*first_cmd = 3;
		*append = 1;
	}
	else
	{
		*first_cmd = 2;
		*append = 0;
	}
}

/*opens infile and outfile*/
/*opens infile when there is no here_doc*/
/*if there is an error opening infile an error is stored in stderr*/
void	files_init(char	*infile, char *outfile, int	*file, int append)
{
	if (!append)
	{
		file[0] = open (infile, O_RDONLY);
		if (file[0] == -1)
			error (error_message("no such file or directory: ", infile));
		else
		{
			dup2(file[0], 0);
			close(file[0]);
		}
	}
	else
	{
		dup2(file[0], 0);
		close (file[0]);
	}
	if (append)
		file[1] = open (outfile, O_RDWR | O_CREAT | O_APPEND, 0777);
	else
		file[1] = open (outfile, O_RDWR | O_CREAT | O_TRUNC, 0777);
}
