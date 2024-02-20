/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaunevik <vaunevik@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:46:46 by vaunevik          #+#    #+#             */
/*   Updated: 2024/02/05 08:07:53 by vaunevik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_print_unsigned(unsigned int u, t_flags *flags, t_check *check)
{
	char		*number;

	if (flags->precision == 0 && flags->width == 0 && u == 0)
		return ;
	number = ft_utoa(u, check);
	if (!number)
		return ;
	flags->length = (int)my_strlen(number);
	if (flags->precision > flags->length)
		flags->precision_padding = flags->precision - flags->length;
	if (flags->width > flags->length + flags->precision_padding)
		flags->width_padding = flags->width - flags->length
			- flags->precision_padding;
	if (u == 0 && flags->precision == 0)
		flags->width_padding++;
	if (flags->left_indent)
		ft_left_indent_u(number, u, flags, check);
	else
		ft_right_indent_u(flags, number, u, check);
	free(number);
	return ;
}

void	ft_left_indent_u(char *number,
		unsigned int u, t_flags *flags, t_check *check)
{
	while (flags->precision_padding-- > 0)
		safe_write('0', check);
	if (u == 0 && flags->precision == 0)
	{
		while (flags->width_padding-- > 0)
			safe_write(' ', check);
		return ;
	}
	safe_putstr(number, flags->length, check);
	while (flags->width_padding-- > 0)
		safe_write(' ', check);
	return ;
}

void	ft_right_indent_u(t_flags *flags,
		char *number, unsigned int u, t_check *check)
{
	while (flags->width_padding-- > 0)
	{
		if (flags->zero && flags->precision < 0)
			safe_write('0', check);
		else
			safe_write(' ', check);
	}
	while (flags->precision_padding-- > 0)
		safe_write('0', check);
	if (u == 0 && flags->precision == 0)
		return ;
	safe_putstr(number, flags->length, check);
	return ;
}
