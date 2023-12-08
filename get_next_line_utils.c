/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:22:19 by agilles           #+#    #+#             */
/*   Updated: 2023/12/08 15:59:08 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i += 2;
	else
		i++;
	return (i);
}

char	*ft_strdup(char *buff)
{
	char	*stock;
	int		i;

	i = 0;
	stock = malloc(ft_strlen(buff) + is_line(buff) * sizeof(char));
	if (!stock)
		return(NULL);
	while (buff[i])
	{
		if (buff[i] == '\n')
		{
			stock[i] = '\n';
			stock[i + 1] = '\0';
			return (stock);
		}
		stock[i] = buff[i];
		i++;
	}
	stock[i] = '\0';
	return(stock);
}

char	*ft_linejoin(char *stock, int pos)
{
	stock[pos] = '\n';
	stock[pos + 1] = '\0';
	return (stock);
}

char	*ft_join(char *stock, char *swap, char *buff, int len)
{
	int	b;
	int	s;

	b = 0;
	s = 0;
	while (len != 0)
	{

		if (swap[s] != '\0')
		{
			stock[s] = swap[s];
			s++;
		}
		else if (buff[b] != '\0' && buff[b] != '\n')
		{
			stock[s + b] = buff[b];
			b++;
		}
		else if (buff[b] == '\n')
			return (ft_linejoin(stock, s + b));
		len--;
	}
	stock[s + b] = '\0';
	return(stock);
}
