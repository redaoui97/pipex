/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 22:53:56 by rnabil            #+#    #+#             */
/*   Updated: 2022/08/16 22:53:58 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*Prints an error message before quitting the program*/
void    error(char *error_message)
{
    ft_printf("%s\n",error_message);
    exit(EXIT_FAILURE);
}

/*Find the real path to a specific command, through the $PATH env variable*/
/*Also checks if the user can have access and execute the command*/
char    *get_path(char *real_path)
{
    char    *path;

    return (path);
}

/*Replication of the strdup function*/
/*Allocates a string similar to the one passed in the parameters*/
char	*ft_strdup(const char *s1)
{
	char	*a;
	size_t	i;

	i = 0;
	a = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!a)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		a[i] = s1[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}