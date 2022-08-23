/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:47:16 by rnabil            #+#    #+#             */
/*   Updated: 2021/12/11 21:09:30 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static	int	nbr_size(unsigned int nbr)
{
	int	count;

	if (!nbr)
		return (1);
	count = 0;
	while (nbr > 0)
	{
		count++;
		nbr /= 16;
	}
	return (count);
}

int	print_hex_upper(unsigned int a)
{
	int				count;

	count = nbr_size(a);
	if (a < 16)
		print_char("0123456789ABCDEF"[a % 16]);
	else
	{
		print_hex_upper(a / 16);
		print_hex_upper(a % 16);
	}
	return (count);
}
