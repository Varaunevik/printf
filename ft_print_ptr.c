/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaunevik <vaunevik@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:47:45 by vaunevik          #+#    #+#             */
/*   Updated: 2024/02/05 08:08:38 by vaunevik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_put_address(long unsigned address, t_check *check)
{
	char	c;

	if (address >= 16)
	{
		ft_put_address(address / 16, check);
		ft_put_address(address % 16, check);
	}
	else
	{
		c = (address % 16) + '0';
		if ((address % 16) > 9)
			c = ((address % 16) + 87);
		safe_write(c, check);
	}
	return ;
}

int	ft_hex_size(long unsigned address)
{
	int	count;

	count = 0;
	if (address >= 16)
	{
		count += ft_hex_size(address / 16);
		count += ft_hex_size(address % 16);
	}
	else
		count++;
	return (count);
}

void	ft_print_ptr(void *ptr, t_flags *flags, t_check *check)
{
	int				length;
	unsigned long	address;

	address = (unsigned long)ptr;
	length = ft_hex_size(address) + 2;
	ft_get_ptr_format(flags, length);
	if (flags->left_indent)
	{
		safe_putstr("0x", 2, check);
		ft_put_address(address, check);
		while (flags->width-- > 0)
			safe_write(' ', check);
		return ;
	}
	while (flags->width-- > 0)
		safe_write(' ', check);
	safe_putstr("0x", 2, check);
	ft_put_address(address, check);
	return ;
}

void	ft_get_ptr_format(t_flags *flags, int length)
{
	if (flags->precision != -1)
	{
		if (flags->precision < length)
			flags->width -= flags->precision;
		else
			flags->width -= length;
		return ;
	}
	flags->width -= length;
	return ;
}
