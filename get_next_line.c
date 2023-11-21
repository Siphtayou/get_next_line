/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:15:35 by agilles           #+#    #+#             */
/*   Updated: 2023/11/20 15:08:02 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		ft_line(buff, stock);
}
