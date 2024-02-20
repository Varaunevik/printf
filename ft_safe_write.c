/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaunevik <vaunevik@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 08:09:54 by vaunevik          #+#    #+#             */
/*   Updated: 2024/02/05 08:10:16 by vaunevik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	safe_write(char c, t_check *check)
{
	if (!check->error)
	{
		if (write(1, &c, 1) == -1)
		{
			check->error = 1;
			check->len = -1;
		}
		else
			check->len += 1;
	}
}
