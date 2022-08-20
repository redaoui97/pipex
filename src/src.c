/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 22:53:56 by rnabil            #+#    #+#             */
/*   Updated: 2022/08/16 22:53:58 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*Prints an error message before quitting the program*/
void    error(char *error_message)
{
    printf("%s\n",error_message);//Change this to ft_printf
    exit(EXIT_FAILURE);
}

/*Find the real path to a specific command, through the $PATH env variable*/
/*Also checks if the user can have access and execute the command*/
char    *get_path(char *real_path)
{
    char    *path;

    return (path);
}
