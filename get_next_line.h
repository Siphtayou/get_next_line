/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:22:13 by agilles           #+#    #+#             */
/*   Updated: 2023/12/08 18:02:36 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
void	ft_newline(char *buff);
int		is_line(char *buff);
int		is_line(char *buff);

int		ft_strlen(char *str);
char	*ft_strdup(char *buff);
char	*ft_linejoin(char *stock, int pos);
char	*ft_join(char *stock, char *swap, char *buff, int len);

#endif
