/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktshikot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 09:56:26 by ktshikot          #+#    #+#             */
/*   Updated: 2016/06/05 09:56:28 by ktshikot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_ll(char format, va_list argp)
{
	if (format == 'd' || format == 'i')
		ft_printf("%D", va_arg(argp, long long));
	if (format == 'o')
		ft_printf("%o", (unsigned long long)va_arg(argp, long long));
	if (format == 'u')
		ft_printf("%u", (unsigned long long)va_arg(argp, long long));
	if (format == 'x')
		ft_printf("%x", (unsigned long long)va_arg(argp, long long));
	if (format == 'X')
		ft_printf("%X", (unsigned long long)va_arg(argp, long long));
}

void	handle_h(char format, va_list argp)
{
	if (format == 'd' || format == 'i')
	{
		ft_printf("%s", ft_itoa((short)va_arg(argp, int)));
	}
	else if (format == 'o' || format == 'u' || format == 'x' || format == 'X')
	{
		if (format == 'o')
			ft_printf("%o", (unsigned short)va_arg(argp, int));
		if (format == 'u')
			ft_printf("%u", (unsigned short)va_arg(argp, int));
		if (format == 'x')
			ft_printf("%x", (unsigned short)va_arg(argp, int));
		if (format == 'X')
			ft_printf("%X", (unsigned short)va_arg(argp, int));
	}
}

void	handle_hh(char format, va_list argp)
{
	if (format == 'd' || format == 'i')
		ft_printf("%d", (char)va_arg(argp, int));
	else if (format == 'o' || format == 'u' || format == 'x' || format == 'X')
	{
		if (format == 'o')
			ft_printf("%o", (unsigned char)va_arg(argp, int));
		if (format == 'u')
			ft_printf("%u", (unsigned char)va_arg(argp, int));
		if (format == 'x')
			ft_printf("%x", (unsigned char)va_arg(argp, int));
		if (format == 'X')
			ft_printf("%X", (unsigned char)va_arg(argp, int));
	}
}

void	handle_z(char format, va_list argp)
{
	if (format == 'd' || format == 'i')
		ft_printf("%D", (long)va_arg(argp, int));
	if (format == 'o')
		ft_printf("%o", (long)va_arg(argp, int));
	if (format == 'u')
		ft_printf("%u", (long)va_arg(argp, int));
	if (format == 'x')
		ft_printf("%x", (long)va_arg(argp, int));
	if (format == 'X')
		ft_printf("%X", (long)va_arg(argp, int));
}

void	handle_j(char format, va_list argp)
{
	if (format == 'd' || format == 'i')
		ft_printf("%D", (long)va_arg(argp, intmax_t));
	if (format == 'o')
		ft_printf("%o", (long)va_arg(argp, uintmax_t));
	if (format == 'u')
		ft_printf("%u", (long)va_arg(argp, uintmax_t));
	if (format == 'x')
		ft_printf("%x", (long)va_arg(argp, uintmax_t));
	if (format == 'X')
		ft_printf("%X", (long)va_arg(argp, uintmax_t));
}
