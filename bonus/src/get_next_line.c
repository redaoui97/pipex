/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:50:09 by rnabil            #+#    #+#             */
/*   Updated: 2022/09/06 10:58:29 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	init_function(char **text, char **buffer)
{
	if (!(*text))
		*text = ft_strdup("");
	*buffer = ft_calloc(sizeof(char), BUFFER_SIZE);
	if (!(*buffer))
		return (0);
	return (1);
}

char	*fix_line_text(char **text, char **line, int nl_position)
{
	*line = ft_substr(*text, 0, nl_position + 1);
	*text = fix_text(&*text, nl_position + 1);
	return (*line);
}

char	*fix_text(char **str, int nl_position)
{
	char	*text;
	int		text_length;

	text_length = ft_strlen(*str + nl_position);
	text = ft_substr(*str, nl_position, text_length);
	free(*str);
	*str = NULL;
	return (text);
}

int	check_newline(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*buffer;
	char		*line;
	int			read_value;
	int			nl_position;

	if (!init_function(&text, &buffer))
		return (NULL);
	read_value = read(fd, buffer, BUFFER_SIZE);
	while (read_value >= 0)
	{
		buffer[read_value] = '\0';
		text = ft_strjoin(text, buffer);
		nl_position = check_newline(text);
		if (nl_position != -1)
			return (free(buffer), fix_line_text(&text, &line, nl_position));
		if (!read_value && !text[0])
			break ;
		if (!read_value)
			return (free(buffer), fix_text(&text, 0));
		read_value = read(fd, buffer, BUFFER_SIZE);
	}
	free(text);
	text = NULL;
	return (free(buffer), NULL);
}
