/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaunevik <vaunevik@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:21:43 by vaunevik          #+#    #+#             */
/*   Updated: 2024/02/05 08:03:06 by vaunevik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_print_char(char c, t_flags *flags, t_check *check)
{
	flags->width--;
	if (flags->left_indent)
	{
		safe_write(c, check);
		while (flags->width-- > 0)
			safe_write(' ', check);
		return ;
	}
	while (flags->width-- > 0)
		safe_write(' ', check);
	safe_write(c, check);
	return ;
}
