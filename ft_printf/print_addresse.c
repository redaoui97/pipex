/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_addresse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:13:05 by rnabil            #+#    #+#             */
/*   Updated: 2022/09/06 10:58:05 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static	int	nbr_size(unsigned long int nbr)
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

static void	print_hex(unsigned long int a)
{
	if (a < 16)
		print_char("0123456789abcdef"[a % 16]);
	else
	{
		print_hex(a / 16);
		print_hex(a % 16);
	}
}

int	print_addresse(unsigned long int adr)
{
	int	count;

	count = nbr_size((unsigned long int)adr) + 2;
	print_str("0x");
	print_hex(adr);
	return (count);
}
