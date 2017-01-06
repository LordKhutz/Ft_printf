/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktshikot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 15:19:43 by ktshikot          #+#    #+#             */
/*   Updated: 2016/06/02 15:19:45 by ktshikot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pointer_s(va_list argp, char format, t_printret *ret)
{
	if (format == 'p')
	{
		ft_putstr("0x");
		base_l((unsigned long)va_arg(argp, long), format, 16, ret);
	}
}

int		handle_space_padding(const char *format)
{
	int		num;
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(10);
	while ((int)*++format >= (int)'0' && *format <= (int)'9' && i < 10)
	{
		str[i] = *format;
		i++;
	}
	str[i] = '\0';
	num = ft_atoi(str);
	num -= 1;
	while (num-- > 0)
		ft_putchar(' ');
	return (i + 1);
}

int		handle_0_padding(const char *format)
{
	int		num;
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(10);
	while ((int)*++format >= 48 && *format <= 57 && i < 10)
	{
		str[i] = *format;
		i++;
	}
	str[i] = '\0';
	num = ft_atoi(str);
	num -= 1;
	while (num-- > 0)
		ft_putchar('0');
	return (i + 1);
}
