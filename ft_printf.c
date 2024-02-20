/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pribtf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaunevik <vaunevik@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:41:27 by vaunevik          #+#    #+#             */
/*   Updated: 2024/02/05 08:05:46 by vaunevik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_conversion(const char **str, va_list *args, t_check *check)
{
	t_flags	flags;

	ft_init_flags(&flags);
	ft_bonus_flags(str, &flags);
	if (**str == 'c')
		ft_print_char((char)va_arg(*args, int), &flags, check);
	else if (**str == 'd' || **str == 'i')
		ft_print_int(va_arg(*args, int), &flags, check);
	else if (**str == 's')
		ft_print_string(va_arg(*args, char *), &flags, check);
	else if (**str == '%')
		ft_print_char('%', &flags, check);
	else if (**str == 'u')
		ft_print_unsigned(va_arg(*args, unsigned int), &flags, check);
	else if (**str == 'p')
		ft_print_ptr(va_arg(*args, void *), &flags, check);
	else if (**str == 'x')
		ft_print_hex(va_arg(*args, unsigned int), 0, &flags, check);
	else if (**str == 'X')
		ft_print_hex(va_arg(*args, unsigned int), 1, &flags, check);
	else
		check->len = -1;
	(*str)++;
	return ;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_check	check;	

	va_start(args, str);
	ft_init_check(&check);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_conversion(&str, &args, &check);
		}
		else if (check.len == -1)
		{
			va_end(args);
			return (-1);
		}
		else
		{
			safe_write(*str, &check);
			str++;
		}
	}
	va_end(args);
	return (check.len);
}

void	ft_init_check(t_check *check)
{
	check->error = 0;
	check->len = 0;
	check->width = 0;
}
