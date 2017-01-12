#include "ft_printf.h"

t_printret	*ft_create(void)
{
	t_printret	*create;

	create = (t_printret *)malloc(sizeof(t_printret) * 2);
	create->chars_printed = 0;
	create->padding_num = 0;
	create->padding_type = ' ';
	create->padding_justify = 0;
	create->forcepositive = 0;
	create->format_num = 0;
	create->precision = -2;
	create->isnumber = 0;
	create->format = NULL;
	create->outvalue = NULL;
	create->outval_num = 0;
	create->hashable = 0;
	return (create);
}

void	ft_inner_printf(t_printret	*ret, va_list argp)
{
    int i;

	while (ret->format[ret->counter])
	{
		if (ret->format[ret->counter] == '%')
		{
			ret->counter += 1;
			ft_conversions(ret, argp);
			ft_handle_str(ret, argp);
			handle_length(argp, ret);
			ft_handle_numb(ret, argp);
			ret->counter -= 1;
		}
		else
		{
			ft_putchar(ret->format[ret->counter]);
			ret->chars_printed += 1;
		}
		ret->counter += 1;
	}
}

int			ft_printf(const char *frmt, ...)
{
	va_list		argp;
	t_printret	*ret;
	char 	*format;

	va_start(argp, frmt);
	ret = ft_create();
	format = (char *)malloc(ft_strlen(frmt) + 1);
	while (frmt[ret->counter])
	{
		format[ret->counter] = frmt[ret->counter];
		ret->counter += 1;
	}
	format[ret->counter] = '\0';
	ret->format = format;
	ret->counter = 0;
	ft_inner_printf(ret, argp);
	return (ret->chars_printed);
}
