/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:22:19 by agilles           #+#    #+#             */
/*   Updated: 2023/12/07 15:44:08 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_strdup(char *stock)
{
	char	*temp;
	int		i;

	i = 0;
	temp = malloc(ft_strlen(stock) * sizeof(char));
	if (!temp)
		return(NULL);
	while (stock[i])
	{
		temp[i] = stock[i];
		i++;
	}
	temp[i] = '\0';
	return(temp);
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
	while (len != 0 || buff[b] != '\n')
	{
		if (swap[s] != '\0')
		{
			stock[s] = swap[s];
			s++;
		}
		else
		{
			stock[s + b] = buff[b];
			b++;
		}
		len--;
	}
	if (buff[b] == '\n')
		return (ft_linejoin(stock, s + b));
	stock[s + b] = '\0';
	return(stock);
}
