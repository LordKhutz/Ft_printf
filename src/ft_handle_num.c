/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktshikot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 15:15:48 by ktshikot          #+#    #+#             */
/*   Updated: 2016/06/02 15:15:51 by ktshikot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*check_others(va_list argp, char format)
{
	char	*str;
	long	num;

	str = "";
	num = 0;
	if (format == 'O')
	{
		num = va_arg(argp, long);
		base_l(num, format, 8);
	}
	if (format == 'U')
	{
		num = va_arg(argp, long);
		str = ft_itoa((unsigned long)num);
	}
	return (str);
}

static void		display_num(char *str, int pos_num, int di, int num)
{
	if (pos_num-- == 1 && num > 0 && di == 1)
	{
		ft_putchar('+');
		ft_putstr(str);
	}
	else if (pos_num != 1 && di == 1)
		ft_putstr(str);
}

void			handle_num(va_list argp, char format, int pos_num)
{
	char	*str;
	long	num;
	int		di;

	di = 0;
	num = 0;
	if (format == 'd' || format == 'i')
	{
		di = 1;
		num = va_arg(argp, int);
		str = ft_itoa(num);
	}
	else if (format == 'D')
	{
		di = 1;
		num = va_arg(argp, long);
		str = ft_itoa(num);
	}
	else
		str = check_others(argp, format);
	display_num(str, pos_num, di, num);
}
