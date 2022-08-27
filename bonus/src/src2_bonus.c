/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 12:54:01 by rnabil            #+#    #+#             */
/*   Updated: 2022/08/20 12:54:33 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

/*************************  Functions collection 2 ****************************/

/*allocates and returns pointer to a substring starting from a specific pos*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return ((char *) ft_calloc(1, sizeof(char)));
	if (ft_strlen(s) <= start + len)
		substr = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (s[start] && i < len)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}

/*allocates a given size of memory and overrates the memory cases with NULL*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*res;
	int		i;

	res = malloc(size * count);
	if (!res)
		return (0);
	i = size * count;
	while (i--)
		*((unsigned char *)(res + i)) = 0;
	return (res);
}

/*allocates and copies the 2 strings given in param into the allocated space*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
		str[s1_len++] = s2[i++];
	str[s1_len] = '\0';
	free((void *)s1);
	s1 = NULL;
	return (str);
}

/*allocates and copies the string given in param into the allocated space*/
char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	s1_len;
	int		i;

	i = 0;
	s1_len = ft_strlen(s1);
	copy = malloc(sizeof(char) * (s1_len + 1));
	if (!copy)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

/*concatenates and returns an error message*/
char	*error_message(char *str1, char *str2)
{
	char	*res;

	res = ft_strdup(str1);
	res = ft_strjoin(res, str2);
	res = ft_strjoin(res, "\n");
	return (res);
}
