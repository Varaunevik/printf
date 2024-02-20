/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaunevik <vaunevik@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 07:45:05 by vaunevik          #+#    #+#             */
/*   Updated: 2024/02/05 08:11:14 by vaunevik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

t_flags	*ft_init_flags(t_flags *flags)
{
	flags->left_indent = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->hash = 0;
	flags->zero = 0;
	flags->precision = 0;
	flags->width = 0;
	flags->width_padding = 0;
	flags->precision_padding = 0;
	flags->positive = 0;
	flags->length = 0;
	return (flags);
}

void	ft_bonus_flags(const char **str, t_flags *flags)
{
	while (**str == '0' || **str == ' ' || **str == '#'
		|| **str == '+' || **str == '-')
	{
		if (**str == '0')
			flags->zero = 1;
		else if (**str == ' ')
			flags->space = 1;
		else if (**str == '#')
			flags->hash = 1;
		else if (**str == '+')
			flags->plus = 1;
		else if (**str == '-')
			flags->left_indent = 1;
		(*str)++;
	}
	ft_check_more_flags(str, flags);
}

void	ft_check_more_flags(const char **str, t_flags *flags)
{
	ft_get_width(str, flags);
	if (**str == '.')
	{
		(*str)++;
		while (**str >= '0' && **str <= '9')
		{
			flags->precision = (flags->precision * 10) + (**str - '0');
			(*str)++;
		}
	}
	else
		flags->precision = -1;
}

void	ft_get_width(const char **str, t_flags *flags)
{
	while (**str >= '0' && **str <= '9')
	{
		flags->width = (flags->width * 10) + (**str - '0');
		(*str)++;
	}
}
