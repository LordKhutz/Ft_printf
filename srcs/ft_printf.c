/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktshikot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 10:29:26 by ktshikot          #+#    #+#             */
/*   Updated: 2016/05/27 12:00:44 by ktshikot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	l_justify(const char *format)
{
	int i;

	i = 0;
	while (*format++ == '-')
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}

static int	conversions(char *format, va_list argp, int pos_num)
{
	int	i;

	i = 0;
	if (*format == '-')
		i += l_justify(format);
	print_string(argp, *format);
	if (ft_isdigit(*format) != -1)
		i += handle_padding(format, argp);
	if (*format == '0')
		i += handle_0_padding(format);
	if (*format == ' ')
		i += handle_space_padding(format);
	if (*format == '+')
	{
		i += 1;
		pos_num = 1;
	}
	if (*format == '#')
	{
		i += 1;
		handle_hashtag(*++format);
	}
	i += handle_length(format, argp);
	return (i);
}

int			ft_printf(const char *format, ...)
{
	va_list	argp;
	int		pos_num;

	pos_num = 0;
	va_start(argp, format);
	while (*format)
	{
		if (*format == '%')
		{
			format += 1;
			format += conversions((char *)format, argp, pos_num);
			handle_num(argp, *format, pos_num);
			pointer_s(argp, *format);
			base_change(argp, *format);
			double_percent(*format);
		}
		else
			ft_printf("%c", *format);
		format += 1;
	}
	return (0);
}
