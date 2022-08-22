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
# ifndef MAX_FD
#  define MAX_FD 65535
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE    1
# endif

/*ft_printf functions*/
int		ft_printf(const char *f, ...);
size_t	ft_strlen(const char *s);
int		print_addresse(unsigned long int adr);
int		print_char(char chr);
int		print_hex_lower(unsigned int a);
int		print_hex_upper(unsigned int a);
int		print_nbr_unsigned(unsigned int n);
int		print_nbr(int n);
int		print_str(char *str);

/*get_next_line functions*/
char	*get_next_line(int fd);
int		init_function(char **text, char **buffer);
char	*fix_line_text(char **text, char **line, int nl_position);
char	*fix_text(char **str, int nl_position);
int		check_newline(char *buffer);

/*split*/
char	**ft_split(char const *s, char c);

/*src functions*/
void	error(char *error_message);
char	*get_path(char *real_path);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	free_words(char **words);

/*src2 functions*/
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);

/*parsin functions*/

/*main functions*/

#endif
