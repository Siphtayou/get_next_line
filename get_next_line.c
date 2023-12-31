/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:15:35 by agilles           #+#    #+#             */
/*   Updated: 2023/12/08 18:09:27 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_newline(char *buff)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	while (buff[len])
		len++;
	j = 0;
	i = 0;
	while (buff[i] != '\n')
		i++;
	i++;
	while (j < (len - i))
	{
		buff[j] = buff[j + i];
		j++;
	}
	buff[j] = '\0';
}

int	is_line(char *buff)
{
	int	i;

	i = 0;
	if (!buff)
		return (0);
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_line(char *buff, char *stock)
{
	char	*swap;
	int		len;

	if (!stock)
		stock = ft_strdup(buff);
	else
	{
		swap = ft_strdup(stock);
		free(stock);
		if (!swap)
			return (NULL);
		len = (ft_strlen(buff) + ft_strlen(swap));
		stock = malloc((len) * sizeof(char));
		stock = ft_join(stock, swap, buff, len);
		free(swap);
	}
	if (!stock)
		return (NULL);
	return (stock);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*stock;
	int			byte;

	stock = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (is_line(buff))
	{
		ft_newline(buff);
		stock = ft_line(buff, stock);
		if (is_line(stock))
			return (stock);
	}
	while (!is_line(buff))
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == 0)
			return (stock);
		else if (byte == -1)
			return (free(stock), NULL);
		buff[byte] = '\0';
		stock = ft_line(buff, stock);
	}
	return (stock);
}
