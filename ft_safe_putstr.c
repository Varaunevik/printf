/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_putstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaunevik <vaunevik@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 08:09:10 by vaunevik          #+#    #+#             */
/*   Updated: 2024/02/05 08:09:38 by vaunevik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	safe_putstr(const char *s, int len, t_check *check)
{
	while (len > 0)
	{
		safe_write(*s, check);
		len--;
		s++;
	}
}
