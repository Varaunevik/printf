/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaunevik <vaunevik@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 08:05:36 by vaunevik          #+#    #+#             */
/*   Updated: 2024/02/05 08:01:44 by vaunevik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_get_size(unsigned int u)
{
	int	count;

	count = 0;
	if (u >= 16)
	{
		count += ft_get_size(u / 16);
		count += ft_get_size(u % 16);
	}
	else
		count++;
	return (count);
}

void	ft_print_hex(unsigned int u, int upper, t_flags *flags, t_check *check)
{
	if (u == 0)
		flags->hash = 0;
	if (flags->precision == 0 && flags->width == 0 && u == 0)
		return ;
	flags->length = ft_get_size(u);
	if (flags->precision > flags->length)
		flags->precision_padding = flags->precision - flags->length;
	if (flags->width > flags->length + flags->precision_padding)
		flags->width_padding = flags->width - flags->length
			- flags->precision_padding;
	if (flags->hash)
		flags->width_padding -= 2;
	if (u == 0 && flags->precision == 0)
		flags->width_padding++;
	if (!flags->left_indent)
		ft_right_indent_h(flags, u, upper, check);
	else
		ft_left_indent_h(flags, u, upper, check);
	return ;
}

void	ft_left_indent_h(t_flags *flags, unsigned int u,
		int upper, t_check *check)
{
	if (flags->hash)
	{
		if (upper == 1)
			safe_putstr("0X", 2, check);
		else if (upper == 0)
			safe_putstr("0x", 2, check);
	}
	while (flags->precision_padding-- > 0)
		safe_write('0', check);
	if (u == 0 && flags->precision == 0)
	{
		while (flags->width_padding-- > 0)
			safe_write(' ', check);
		return ;
	}
	ft_put_hex(u, upper, check);
	while (flags->width_padding-- > 0)
		safe_write(' ', check);
	return ;
}

void	ft_right_indent_h(t_flags *flags,
		unsigned int u, int upper, t_check *check)
{
	if (flags->zero && flags->precision == -1)
	{
		ft_right_and_zero(flags, u, upper, check);
		return ;
	}
	while (flags->width_padding-- > 0)
		safe_write(' ', check);
	if (flags->hash)
	{
		if (upper == 1)
			safe_putstr("0X", 2, check);
		else if (upper == 0)
			safe_putstr("0x", 2, check);
	}
	while (flags->precision_padding-- > 0)
		safe_write('0', check);
	if (u == 0 && flags->precision == 0)
		return ;
	ft_put_hex(u, upper, check);
	return ;
}

void	ft_right_and_zero(t_flags *flags,
		unsigned int u, int upper, t_check *check)
{
	if (flags->hash)
	{
		if (upper == 1)
			safe_putstr("0X", 2, check);
		else if (upper == 0)
			safe_putstr("0x", 2, check);
	}
	while (flags->width_padding-- > 0)
		safe_write('0', check);
	ft_put_hex(u, upper, check);
	return ;
}
