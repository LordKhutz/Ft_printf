/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktshikot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 15:21:30 by ktshikot          #+#    #+#             */
/*   Updated: 2016/06/05 09:56:39 by ktshikot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		double_percent(char format)
{
	if (format == '%')
		ft_putchar('%');
}

void		handle_hashtag(char format)
{
	if (format == 'X')
		ft_putstr("0X");
	if (format == 'x')
		ft_putstr("0x");
	if (format == 'o')
		ft_putchar('0');
}

static void	do_some_other_stuff(char *str, int *n, char format, va_list argp)
{
	char	*s;

	if (format == 's')
	{
		s = va_arg(argp, char *);
		n[1] = ft_strlen(s);
		while (n[3] < n[1] && (n[0] > 0 || n[1] > n[0]))
		{
			ft_putchar(s[n[3]]);
			n[3]++;
			n[0]--;
		}
	}
	else
	{
		n[3] = va_arg(argp, long);
		str = ft_itoa(n[3]);
		n[4] = 1;
		n[0] -= ft_strlen(str);
	}
}

static void	do_some_display(int i, int j, char *str, char format)
{
	while (i-- > 0)
		ft_putchar(' ');
	if (j == 1)
	{
		ft_printf("%s", str);
		if (format == '\n')
			ft_printf("%c", '\n');
	}
}

int			handle_padding(const char *format, va_list argp)
{
	char	*str;
	int		n[5];

	n[2] = 0;
	n[3] = 0;
	n[4] = 0;
	str = (char *)malloc(10);
	while ((int)*format > 48 && (int)*format <= 57 && n[2] < 10)
	{
		str[n[2]] = *format;
		format += 1;
		n[2]++;
	}
	str[n[2]] = '\0';
	n[0] = ft_atoi(str);
	free(str);
	str = (char *)malloc(n[0]);
	do_some_other_stuff(str, &*n, *format, argp);
	do_some_display(n[0], n[4], str, *++format);
	return (n[2] + n[4]);
}
