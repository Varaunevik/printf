/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaunevik <vaunevik@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:51:26 by vaunevik          #+#    #+#             */
/*   Updated: 2024/02/05 10:45:30 by vaunevik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_flags
{
	int			left_indent;
	int			plus;
	int			space;
	int			hash;
	int			zero;
	int			precision;
	int			width;
	int			width_padding;
	int			precision_padding;
	long int	positive;
	int			length;
}	t_flags;

typedef struct s_check
{
	int	error;
	int	len;
	int	width;
}	t_check;

int			ft_printf(const char *str, ...);
void		ft_conversion(const char **str, va_list *args, t_check *check);
t_flags		*ft_init_flags(t_flags *flags);

void		ft_bonus_flags(const char **str, t_flags *flags);
void		ft_check_more_flags(const char **str, t_flags *flags);
void		ft_get_width(const char **str, t_flags *flags);

void		ft_print_hex(unsigned int u, int upper,
				t_flags *flags, t_check *check);
void		ft_put_hex(unsigned int u, int upper, t_check *check);

void		ft_print_char(char c, t_flags *flags, t_check *check);

void		ft_printstr(char *str, t_flags *flags, t_check *check);
void		ft_print_string(char *str, t_flags *flags, t_check *check);

size_t		ft_intlen(unsigned int n);
char		*ft_utoa(unsigned int n, t_check *check);
void		ft_print_unsigned(unsigned int u, t_flags *flags, t_check *check);

void		ft_get_ptr_format(t_flags *flags, int length);
int			ft_hex_size(long unsigned address);
void		ft_print_ptr(void *ptr, t_flags *flags, t_check *check);
void		ft_get_ptr_format(t_flags *flags, int length);
void		ft_put_address(long unsigned address, t_check *check);

void		ft_print_int(int nbr, t_flags *flags, t_check *check);
void		ft_left_indent_int(t_flags *flags,
				char *number, int nbr, t_check *check);
void		ft_right_indent_int(t_flags *flags,
				char *number, int nbr, t_check *check);
void		ft_find_padding(t_flags *flags, int nbr);

void		ft_left_indent_h(t_flags *flags,
				unsigned int u, int upper, t_check *check);
void		ft_right_indent_h(t_flags *flags,
				unsigned int u, int upper, t_check *check);
void		ft_right_and_zero(t_flags *flags,
				unsigned int u, int upper, t_check *check);

void		ft_sign_and_zero(t_flags *flags, int nbr,
				char *number, t_check *check);
void		ft_left_indent_u(char *number,
				unsigned int u, t_flags *flags, t_check *check);
void		ft_right_indent_u(t_flags *flags,
				char *number, unsigned int u, t_check *check);
size_t		my_strlen(char *str);
void		ft_extra_conversion(const char **str, va_list *args,
				t_flags *flags, t_check *check);
void		safe_write(char c, t_check *check);
void		safe_putstr(const char *s, int len, t_check *check);
void		ft_init_check(t_check *check);

#endif
