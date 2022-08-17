/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:59:19 by rnabil            #+#    #+#             */
/*   Updated: 2021/12/11 14:34:59 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	print_nbr_unsigned(unsigned int n)
{
	unsigned int	a;
	int				count;

	a = n;
	count = 1;
	if (a < 10)
		print_char((a + '0'));
	else
	{
		count += print_nbr_unsigned(a / 10);
		print_char(a % 10 + '0');
	}
	return (count);
}
