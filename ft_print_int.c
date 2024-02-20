/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaunevik <vaunevik@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:10:04 by vaunevik          #+#    #+#             */
/*   Updated: 2024/02/05 08:03:53 by vaunevik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_find_padding(t_flags *flags, int nbr)
{
	if (flags->precision > flags->length)
		flags->precision_padding = flags->precision - flags->length;
	if (flags->width > flags->length + flags->precision_padding)
		flags->width_padding = flags->width - flags->length
			- flags->precision_padding;
	if (flags->space || flags->plus || nbr < 0)
		flags->width_padding--;
	return ;
}

void	ft_print_int(int nbr, t_flags *flags, t_check *check)
{
	char		*number;

	if (flags->precision == 0 && flags->width == 0 && nbr == 0
		&& flags->plus == 0 && flags->space == 0)
		return ;
	if (nbr < 0)
		flags->positive = ((long int)nbr * -1);
	else
		flags->positive = nbr;
	number = ft_utoa(flags->positive, check);
	if (!number)
		return ;
	flags->length = (int)my_strlen(number);
	ft_find_padding(flags, nbr);
	if (nbr == 0 && flags->precision == 0)
		flags->width_padding++;
	if (!flags->left_indent)
		ft_right_indent_int(flags, number, nbr, check);
	else
		ft_left_indent_int(flags, number, nbr, check);
	free (number);
	return ;
}

void	ft_left_indent_int(t_flags *flags, char *number,
		int nbr, t_check *check)
{
	if (flags->plus && nbr >= 0)
		safe_write('+', check);
	else if (flags->space && nbr >= 0)
		safe_write(' ', check);
	else if (nbr < 0)
		safe_write('-', check);
	while (flags->precision_padding-- > 0)
		safe_write('0', check);
	if (nbr == 0 && flags->precision == 0)
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

void	ft_right_indent_int(t_flags *flags, char *number,
		int nbr, t_check *check)
{
	if (flags->zero && flags->precision < 0)
	{
		ft_sign_and_zero(flags, nbr, number, check);
		return ;
	}
	while (flags->width_padding-- > 0)
		safe_write(' ', check);
	if (flags->plus && nbr >= 0)
		safe_write('+', check);
	else if (flags->space && nbr >= 0)
		safe_write(' ', check);
	else if (nbr < 0)
		safe_write('-', check);
	while (flags->precision_padding-- > 0)
		safe_write('0', check);
	if (nbr == 0 && flags->precision == 0)
		return ;
	else
		safe_putstr(number, flags->length, check);
	return ;
}

void	ft_sign_and_zero(t_flags *flags, int nbr, char *number, t_check *check)
{
	if (flags->plus && nbr >= 0)
		safe_write('+', check);
	else if (flags->space && nbr >= 0)
		safe_write(' ', check);
	else if (nbr < 0)
		safe_write('-', check);
	while (flags->width_padding-- > 0)
		safe_write('0', check);
	safe_putstr(number, flags->length, check);
	return ;
}
