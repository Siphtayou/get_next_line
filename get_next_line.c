/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:15:35 by agilles           #+#    #+#             */
/*   Updated: 2023/11/29 16:19:03 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_newline(char *buff, char *stock)
{
	int	i;

	i = 0;
	while (buff[i] != '\n' || buff[i] != '\0')
	{
		
	}
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*stock;
	int			byte;

	stock = NULL;
	buff[BUFFER_SIZE + 1] = "";
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buff)
		ft_newline(buff, stock); // cut tout jusqua \n et stock le reste dans stock
	while (!is_line(buff)) // is_line verifie si ya \n
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == BUFFER_SIZE || byte == 0)
			buff[byte] = '\0';
		ft_line(buff, stock); // ft_line deplace buff dans stock mais sarrete apres \n ou \0 si ya dans buff
	}
	return(stock);
}
