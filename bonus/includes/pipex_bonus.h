/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:50:09 by rnabil            #+#    #+#             */
/*   Updated: 2022/08/15 20:51:09 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <stdarg.h>

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
size_t	ft_strlen(const char *s);

/*split*/
char	**ft_split(char const *s, char c);

/*src functions*/
void	error(char *error_message);
void	fatal_error(char *error_message);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	free_words(char **words);
int		has_non_alpha(char *str);

/*src2 functions*/
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*error_message(char *str1, char *str2);

/*parsing functions*/
void	parsing(int argc, char **argv, char **envp, int start);

/*parsing utils functions*/
char	*path_env(char **envp);
char	*get_path(char *cmd, char *env_path);
void	check_heredoc(char **argv, int *first_cmd, int *append);
#endif
