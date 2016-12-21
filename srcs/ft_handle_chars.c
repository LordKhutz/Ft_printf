/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handleChars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktshikot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 15:11:51 by ktshikot          #+#    #+#             */
/*   Updated: 2016/06/02 15:11:54 by ktshikot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_string(va_list argp, char format)
{
	wchar_t	*w_s;

	if (format == 's')
		ft_putstr(va_arg(argp, char *));
	if (format == 'c')
		ft_putchar(va_arg(argp, int));
	if (format == 'C')
		ft_putchar((char)va_arg(argp, wchar_t));
	if (format == 'S')
	{
		w_s = va_arg(argp, int *);
		while (*w_s)
			ft_putchar((char)*w_s++);
	}
}
