/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:11:47 by rnabil            #+#    #+#             */
/*   Updated: 2021/12/11 17:44:44 by rnabil           ###   ########.fr       */
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
