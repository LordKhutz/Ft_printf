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

static void	handle_l(char format, va_list argp, t_printret *ret)
{
	if (format == 'd' || format == 'i')
		ret->returnvalue += ft_printf("%D", va_arg(argp, long));
	if (format == 'o')
		ret->returnvalue += ft_printf("%o", (unsigned long)va_arg(argp, long));
	if (format == 'u')
		ret->returnvalue += ft_printf("%u", (unsigned long)va_arg(argp, long));
	if (format == 'x')
		ret->returnvalue += ft_printf("%x", (unsigned long)va_arg(argp, long));
	if (format == 'X')
		ret->returnvalue += ft_printf("%X", (unsigned long)va_arg(argp, long));
}

int			jz(const char *format, va_list argp, t_printret *ret)
{
	int	i;

	i = 0;
	if (*format == 'j')
	{
		format += 1;
		handle_j(*format, argp, ret);
		i += 2;
	}
	if (*format == 'z')
	{
		format += 1;
		handle_z(*format, argp, ret);
		i += 2;
	}
	return (i);
}

int			hh(const char **format, va_list argp, t_printret *ret)
{
	int	i;

	i = 0;
	if (**format == 'h')
	{
		*format += 1;
		if (**format == 'h')
		{
			*format += 1;
			handle_hh(**format, argp, ret);
			i += 2;
		}
		else
			handle_h(**format, argp, ret);
		i += 1;
	}
	return (i);
}

int			handle_length(const char *format, va_list argp, t_printret *ret)
{
	int i;

	i = 0;
	if (*format == 'l')
	{
		format += 1;
		if (*format == 'l')
		{
			format += 1;
			handle_ll(*format, argp, ret);
			i += 1;
		}
		else
			handle_l(*format, argp, ret);
		i += 1;
	}
	i += hh(&format, argp, ret);
	i += jz(format, argp, ret);
	return (i);
}
