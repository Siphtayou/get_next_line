/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:22:19 by agilles           #+#    #+#             */
/*   Updated: 2023/12/07 17:26:50 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	i++;
	return (i);
}

char	*ft_strdup(char *stock)
{
	char	*temp;
	int		i;

	i = 0;
	temp = malloc((ft_strlen(stock) + is_line(stock)) * sizeof(char));
	if (!temp)
		return(NULL);
	while (stock[i])
	{
		if (stock[i] == '\n')
		{
			temp[i] = '\n';
			temp[i + 1] = '\0';
			return (temp);
		}
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
