/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:59:19 by rnabil            #+#    #+#             */
/*   Updated: 2021/12/11 21:10:03 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static	int	nbr_size(int nbr)
{
	int	count;

	if (!nbr)
		return (1);
	count = 0;
	while (nbr > 0)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

int	print_nbr(int n)
{
	unsigned int	a;
	int				count;

	if (n == -2147483648)
		return (print_str ("-2147483648"));
	count = 0;
	if (n < 0)
	{
		print_char('-');
		a = n * -1;
		count++;
	}
	else
		a = n;
	count += nbr_size(a);
	if (a < 10)
		print_char((a + '0'));
	else
	{
		print_nbr(a / 10);
		print_char(a % 10 + '0');
	}
	return (count);
}
