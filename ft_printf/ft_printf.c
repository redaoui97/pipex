/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:07:45 by rnabil            #+#    #+#             */
/*   Updated: 2021/12/11 21:15:17 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	indicator(va_list args, const char f)
{
	if (f == '%')
		return (print_char('%'));
	if (f == 'd' || f == 'i')
		return (print_nbr(va_arg(args, int)));
	if (f == 'u')
		return (print_nbr_unsigned(va_arg(args, unsigned int)));
	if (f == 'c')
		return (print_char((char)va_arg(args, int)));
	if (f == 's')
		return (print_str(va_arg(args, char *)));
	if (f == 'x')
		return (print_hex_lower(va_arg(args, unsigned int)));
	if (f == 'X')
		return (print_hex_upper(va_arg(args, unsigned int)));
	if (f == 'p')
		return (print_addresse(va_arg(args, unsigned long int)));
	return (0);
}

int	ft_printf(const char *f, ...)
{
	va_list	args;
	int		i;
	int		len;

	len = 0;
	i = 0;
	va_start(args, f);
	while (f[i])
	{
		if (f[i] == '%')
		{
			i++;
			len += indicator(args, f[i]);
		}
		else
			len += print_char(f[i]);
		i++;
	}
	va_end(args);
	return (len);
}
