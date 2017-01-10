#include "ft_printf.h"

t_printret	*ft_create(void)
{
	t_printret	*create;

	create = (t_printret *)malloc(sizeof(t_printret) * 2);
	create->chars_printed = 0;
	create->padding_num = 0;
	create->padding_type = ' ';
	create->padding_justify = -1;
	create->format_num = 0;
	create->format = NULL;
	create->outvalue = NULL;
	create->outval_num = 0;
	return (create);
}

void	ft_inner_printf(t_printret	*ret, va_list argp)
{
	while (ret->format[ret->counter])
	{
		if (ret->format[ret->counter] == '%')
		{
			ret->counter += 1;
			ft_handle_str(ret, argp);
			ft_handle_numb(ret, argp);
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

	va_start(argp, frmt);
	ret = ft_create();
	ret->format = frmt;
	ret->counter = 0;
	ft_inner_printf(ret, argp);
	return (ret->chars_printed);
}
