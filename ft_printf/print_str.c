/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:11:47 by rnabil            #+#    #+#             */
/*   Updated: 2022/09/06 10:58:17 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	print_str(char *str)
{
	int	i;

	if (!str)
		return (print_str("(null)"));
	i = 0;
	while ((size_t)i < ft_strlen(str))
	{
		print_char(str[i]);
		i++;
	}
	return (ft_strlen(str));
}

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}
