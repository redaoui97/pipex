/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:50:09 by rnabil            #+#    #+#             */
/*   Updated: 2022/09/04 18:40:51 by rnabil           ###   ########.fr       */
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
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# ifndef MAX_FD
#  define MAX_FD 65535
# endif

typedef struct s_data
{
	int		append;
	int		first_command;
	int		argc;
	int		**pipes;
	int		**heredoc;
	char	**argv;
	char	**envp;
}			t_data;

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

/*src3 functions*/
void	set_data(t_data *data, int argc, char **argv, char **envp);
void	close_fd(int *pipe_fd, int heredoc);
void	close_n_wait(int file);

/*parsing functions*/
void	parsing(int argc, char **argv, char **envp, int start);

/*parsing utils functions*/
char	*path_env(char **envp);
char	*get_path(char *cmd, char *env_path);
void	check_heredoc(char **argv, int *first_cmd, int *append);
void	files_init(char	*infile, char *outfile, int	*file, int append);

/*get_next_line functions*/
char	*get_next_line(int fd);
int		init_function(char **text, char **buffer);
char	*fix_line_text(char **text, char **line, int nl_position);
char	*fix_text(char **str, int nl_position);
int		check_newline(char *buffer);

#endif
