/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktshikot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 15:16:58 by ktshikot          #+#    #+#             */
/*   Updated: 2016/06/02 15:17:04 by ktshikot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		base(unsigned int number_to_convert, char case_, int base, t_printret *rt)
{
	char	*base_digits;
	int		converted_number[64];
	int		index;

	index = 0;
	if (case_ == 'X')
		base_digits = "0123456789ABCDEF";
	else
		base_digits = "0123456789abcdef";
	if (number_to_convert == 0)
	{
		converted_number[index] = 0;
		index += 1;
	}
	while (number_to_convert > 0)
	{
		converted_number[index] = number_to_convert % base;
		number_to_convert = number_to_convert / base;
		++index;
	}
	rt->returnvalue += index;
	while (index--)
	{
		ft_putchar(base_digits[converted_number[index]]);
	}
}

void		base_l(long number_to_convert, char case_, int base, t_printret *rt)
{
	char	*base_digits;
	int		converted_number[64];
	int		index;

	index = 0;
	if (case_ == 'X')
		base_digits = "0123456789ABCDEF";
	else
		base_digits = "0123456789abcdef";
	if (number_to_convert == 0)
	{
		converted_number[index] = 0;
		index += 1;
	}
	while (number_to_convert > 0)
	{
		converted_number[index] = number_to_convert % base;
		number_to_convert = number_to_convert / base;
		++index;
	}
	rt->returnvalue += index;
	while (index--)
	{
		ft_putchar(base_digits[converted_number[index]]);
	}
}

void		base_change(va_list argp, char format, t_printret *ret)
{
	if (format == 'X')
		base(va_arg(argp, int), format, 16, ret);
	if (format == 'x')
		base(va_arg(argp, int), format, 16, ret);
	if (format == 'o')
		base(va_arg(argp, int), format, 8, ret);
}
