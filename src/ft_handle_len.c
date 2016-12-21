/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktshikot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 09:57:01 by ktshikot          #+#    #+#             */
/*   Updated: 2016/06/05 09:57:03 by ktshikot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_l(char format, va_list argp)
{
	if (format == 'd' || format == 'i')
		ft_printf("%D\n", va_arg(argp, long));
	if (format == 'o')
		ft_printf("%o\n", (unsigned long)va_arg(argp, long));
	if (format == 'u')
		ft_printf("%u\n", (unsigned long)va_arg(argp, long));
	if (format == 'x')
		ft_printf("%x\n", (unsigned long)va_arg(argp, long));
	if (format == 'X')
		ft_printf("%X\n", (unsigned long)va_arg(argp, long));
}

int			jz(const char *format, va_list argp)
{
	int	i;

	i = 0;
	if (*format == 'j')
	{
		format += 1;
		handle_j(*format, argp);
		i += 2;
	}
	if (*format == 'z')
	{
		format += 1;
		handle_z(*format, argp);
		i += 2;
	}
	return (i);
}

int			hh(const char **format, va_list argp)
{
	int	i;

	i = 0;
	if (**format == 'h')
	{
		*format += 1;
		if (**format == 'h')
		{
			*format += 1;
			handle_hh(**format, argp);
			i += 2;
		}
		else
			handle_h(**format, argp);
		i += 1;
	}
	return (i);
}

int			handle_length(const char *format, va_list argp)
{
	int i;

	i = 0;
	if (*format == 'l')
	{
		format += 1;
		if (*format == 'l')
		{
			format += 1;
			handle_ll(*format, argp);
			i += 1;
		}
		else
			handle_l(*format, argp);
		i += 1;
	}
	i += hh(&format, argp);
	i += jz(format, argp);
	return (i);
}
