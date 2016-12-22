#include "ft_printf.h"

int length(const char *format,va_list argp)
{
	int i;
	char *str;

	i = 0;
	if (*format == 'l')
	{
		format += 1;
		if (*format == 'l')
		{
			if (*format == 'd' || *format == 'i')
				ft_printf("%D\n",va_arg(argp, long long));
			if (*format == 'o')
				ft_printf("%o\n",(unsigned long long) va_arg(argp, long long));
			if (*format == 'u')
				ft_printf("%u\n",(unsigned long long) va_arg(argp, long long));
			if (*format == 'x')
				ft_printf("%x\n",(unsigned long long) va_arg(argp, long long));
			if (*format == 'X')
				ft_printf("%X\n",(unsigned long long) va_arg(argp, long long));
			i += 2;
		}
		else
		{
			if (*format == 'd' || *format == 'i')
				ft_printf("%D\n",va_arg(argp, long));
			if (*format == 'o')
				ft_printf("%o\n",(unsigned long) va_arg(argp, long));
			if (*format == 'u')
				ft_printf("%u\n",(unsigned long) va_arg(argp, long));
			if (*format == 'x')
				ft_printf("%x\n",(unsigned long) va_arg(argp, long));
			if (*format == 'X')
				ft_printf("%X\n",(unsigned long) va_arg(argp, long));
			i += 1;
		}
	}

	if (*format == 'h')
	{

		format += 1;
		if (*format == 'h')
		{

			format += 1;
			if (*format == 'd' || *format == 'i')
			{
				ft_printf("%d\n",(char) va_arg(argp, int));
				i += 2;
			}
			if (*format == 'o' || *format == 'u' || *format == 'x' || *format == 'X')
			{
				if (*format == 'o')
					ft_printf("%o\n",(unsigned char) va_arg(argp, int));
				if (*format == 'u')
					ft_printf("%u\n",(unsigned char) va_arg(argp, int));
				if (*format == 'x')
					ft_printf("%x\n",(unsigned char) va_arg(argp, int));
				if (*format == 'X')
					ft_printf("%X\n",(unsigned char) va_arg(argp, int));
				i += 2;
			}
		}
		else
		{
			if (*format == 'd' || *format == 'i')
			{
				ft_printf("%d\n",(short) va_arg(argp, int));
				i += 2;
			}
			if (*format == 'o' || *format == 'u' || *format == 'x' || *format == 'X')
			{
				if (*format == 'o')
					ft_printf("%o\n",(unsigned short) va_arg(argp, int));
				if (*format == 'u')
					ft_printf("%u\n",(unsigned short) va_arg(argp, int));
				if (*format == 'x')
					ft_printf("%x\n",(unsigned short) va_arg(argp, int));
				if (*format == 'X')
					ft_printf("%X\n",(unsigned short) va_arg(argp, int));
				i += 2;
			}
			i += 1;
		}
	}
	if (*format == 'j')
	{
		format += 1;
		get_j(*format, argp);
		i += 2;
	}
	if (*format == 'z')
	{
		format += 1;
		if (*format == 'd' || *format == 'i')
			ft_printf("%D\n",(long) va_arg(argp, int));
		if (*format == 'o')
			ft_printf("%o\n",(long) va_arg(argp, int));
		if (*format == 'u')
			ft_printf("%u\n",(long) va_arg(argp, int));
		if (*format == 'x')
			ft_printf("%x\n",(long) va_arg(argp, int));
		if (*format == 'X')
			ft_printf("%X\n",(long) va_arg(argp, int));
		i += 2;
	}
	return (i);
}
void get_j(char format, va_list argp)
{
	if (*format == 'd' || *format == 'i')
		ft_printf("%D\n",(long) va_arg(argp, intmax_t));
	if (*format == 'o')
		ft_printf("%o\n",(long) va_arg(argp, uintmax_t));
	if (*format == 'u')
		ft_printf("%u\n",(long) va_arg(argp, uintmax_t));
	if (*format == 'x')
		ft_printf("%x\n",(long) va_arg(argp, uintmax_t));
	if (*format == 'X')
		ft_printf("%X\n",(long) va_arg(argp, uintmax_t));
}
