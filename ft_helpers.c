/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaunevik <vaunevik@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 09:35:33 by vaunevik          #+#    #+#             */
/*   Updated: 2024/02/05 08:04:45 by vaunevik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

size_t	ft_intlen(unsigned int n)
{
	size_t	i;

	i = 1;
	n /= 10;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_utoa(unsigned int n, t_check *check)
{
	size_t	length;
	char	*result;

	length = ft_intlen(n);
	result = malloc(sizeof(char) * (length + 1));
	if (!result)
	{
		check->error = 1;
		check->len = -1;
		return (NULL);
	}
	result[length] = '\0';
	while (length > 0)
	{
		result[length - 1] = (n % 10) + '0';
		n /= 10;
		length--;
	}
	return (result);
}

size_t	my_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_put_hex(unsigned int u, int upper, t_check *check)
{
	char	c;

	if (u >= 16)
	{
		ft_put_hex(u / 16, upper, check);
		ft_put_hex(u % 16, upper, check);
	}
	else
	{
		c = (u % 16) + '0';
		if ((u % 16) > 9 && upper == 1)
			c = ((u % 16) + 55);
		else if ((u % 16) > 9 && upper == 0)
			c = ((u % 16) + 87);
		safe_write(c, check);
	}
	return ;
}
