/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:50:09 by rnabil            #+#    #+#             */
/*   Updated: 2022/08/15 20:51:09 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdarg.h>

/*Ft_printf functions*/
int			ft_printf(const char *f, ...);
size_t		ft_strlen(const char *s);
int			print_addresse(unsigned long int adr);
int			print_char(char chr);
int			print_hex_lower(unsigned int a);
int			print_hex_upper(unsigned int a);
int			print_nbr_unsigned(unsigned int n);
int			print_nbr(int n);
int			print_str(char *str);

/*Src functions*/
void		error(char *error_message);
#endif
