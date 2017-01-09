/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktshikot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 10:29:26 by ktshikot          #+#    #+#             */
/*   Updated: 2017/01/06 11:40:43 by ktshikot         ###   ########.fr       */
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

static int	conversions(char *format, va_list argp, int pos_num, t_printret *rt)
{
	int	i;

	i = 0;
	if (*format == '-')
		i += l_justify(format);
	print_string(argp, *format, rt);
	if (ft_isdigit(*format) != -1)
		i += handle_padding(format, argp, rt);
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
		handle_hashtag(*++format, rt);
	}
	i += handle_length(format, argp, rt);
	return (i);
}

t_printret	*ft_create(void)
{
	t_printret	*cree;

	cree = (t_printret *)malloc(sizeof(t_printret) * 2);
	cree->returnvalue = 0;
	return (cree);
}

int			ft_printf(const char *format, ...)
{
	va_list		argp;
	int			pos_num;
	t_printret	*ret;

	ret = ft_create();
	pos_num = 0;
	va_start(argp, format);
	while (*format)
	{
		if (*format == '%')
		{
			format += 1;
			format += conversions((char *)format, argp, pos_num, ret);
			ret->returnvalue += handle_num(argp, *format, pos_num, ret);	
			pointer_s(argp, *format, ret);
			base_change(argp, *format, ret);
			if (double_percent(*format))
				ret->returnvalue += 1;
		}
		else
		{
			ft_printf("%c", *format);
			ret->returnvalue += 1;
		}
		format += 1;
	}
	return (ret->returnvalue);
}
