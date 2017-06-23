#include "ft_printf.h"

void ft_wide_chars(t_printret *ret, va_list argp)
{
	wchar_t *w_s;
	char onechar[2];
	int counter;
	char *tmp;

	counter = 0;
	if (ret->format[ret->counter] == 'S')
	{
		w_s = va_arg(argp, int *);
		while (*w_s)
		{
			counter++;
			w_s++;
		}
		w_s -= counter;
		tmp = (char *)malloc(counter);
		while (*w_s)
		{
			*tmp = (char)*w_s;
			tmp++;
			w_s++;
		}
		tmp -= counter;
		ret->outvalue = tmp;
		free(tmp);
		ret->outval_num = ft_strlen(ret->outvalue);
		ret->counter += 1;
	}
	if (ret->format[ret->counter] == 'C')
	{
		onechar[0] = (char)va_arg(argp, wchar_t);
		onechar[1] = '\0';
		ret->outvalue = onechar;
		ret->outval_num = ft_strlen(ret->outvalue);
		ret->counter += 1;
	}
}

void ft_handle_str(t_printret *ret, va_list argp)
{
	char onechar[2];

	if (ret->format[ret->counter] == 's')
	{
		ret->outvalue = va_arg(argp, char *);
		ret->outval_num = ft_strlen(ret->outvalue);
		ret->counter += 1;
	}
	else if (ret->format[ret->counter] == 'c')
	{
		onechar[0] = (char)va_arg(argp, int);
		onechar[1] = '\0';
		ret->outvalue = onechar;
		ret->outval_num = ft_strlen(ret->outvalue);
		ret->counter += 1;
	}
	else
		ft_wide_chars(ret, argp);
	if (ret->outvalue != NULL)
		ft_display(ret);
	ret->outvalue = NULL;
	ret->outval_num = 0;
}
