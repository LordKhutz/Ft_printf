/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handleChars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktshikot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 15:11:51 by ktshikot          #+#    #+#             */
/*   Updated: 2017/01/06 11:35:29 by ktshikot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_string(va_list argp, char format, t_printret *ret)
{
	wchar_t	*w_s;
	char	*str;

	if (format == 's')
	{
		str = va_arg(argp, char *);
		ft_putstr(str);
		ret->returnvalue += ft_strlen(str);
	}
	if (format == 'S')
	{
		w_s = va_arg(argp, int *);
		while (*w_s)
		{
			ft_putchar((char)*w_s++);
			ret->returnvalue += 1;
		}
	}
	if (format == 'c')
	{
		ft_putchar(va_arg(argp, int));
		ret->returnvalue += 1;
	}
	if (format == 'C')
	{
		ft_putchar((char)va_arg(argp, wchar_t));
		ret->returnvalue += 1;
	}
}
