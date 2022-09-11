/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 22:53:56 by rnabil            #+#    #+#             */
/*   Updated: 2022/09/06 10:57:48 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*************************  Functions collection 1 ****************************/

/*prints an error message before quitting the program*/
void	error(char *error_message)
{
	char	*msg;

	msg = ft_strdup("Error occured: ");
	msg = ft_strjoin(msg, error_message);
	write (2, msg, ft_strlen(msg));
	free(msg);
}

void	fatal_error(char *error_message)
{
	error(error_message);
	exit(EXIT_FAILURE);
}

/*compares the first n characters of 2 strings s1 and s2*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return (-1);
}

/*returns 1 if the string has a non-alphabetic character*/
int	has_non_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 'a' && str[i] <= 'z')
			&& !(str[i] >= 'A' && str[i] <= 'Z'))
			return (1);
	}
	return (0);
}

/*Frees arrays of words split*/
void	free_words(char **words)
{
	int	i;

	i = 0;
	while (*words[i])
	{
		free(words[i]);
		i++;
	}
	free (words);
	words = NULL;
}
