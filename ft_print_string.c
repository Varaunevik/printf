/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaunevik <vaunevik@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:44:43 by vaunevik          #+#    #+#             */
/*   Updated: 2024/02/05 08:07:10 by vaunevik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_printstr(char *str, t_flags *flags, t_check *check)
{
	if (flags->precision == -1)
	{
		while (*str != '\0')
		{
			safe_write(*str, check);
			str++;
		}
	}
	else
	{
		while (*str != '\0' && flags->precision-- > 0)
		{
			safe_write(*str, check);
			str++;
		}
	}
	return ;
}

static void	ft_find_wp(char *str, t_flags *flags)
{
	if (flags->precision != -1)
	{
		if ((size_t)flags->precision < my_strlen(str))
			flags->width -= flags->precision;
		else
			flags->width -= my_strlen(str);
		return ;
	}
	flags->width -= my_strlen(str);
	return ;
}

void	ft_print_string(char *str, t_flags *flags, t_check *check)
{
	if (str == NULL)
		ft_find_wp("(null)", flags);
	else
		ft_find_wp(str, flags);
	if (flags->left_indent)
	{
		if (str == NULL)
			ft_printstr("(null)", flags, check);
		else
			ft_printstr(str, flags, check);
		while (flags->width-- > 0)
			safe_write(' ', check);
		return ;
	}
	while (flags->width-- > 0)
		safe_write(' ', check);
	if (str == NULL)
		ft_printstr("(null)", flags, check);
	else
		ft_printstr(str, flags, check);
	return ;
}
