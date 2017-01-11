#include "ft_printf.h"

void	ft_ljf(t_printret *ret)
{
    int i;

    i = 0;
	if (ret->padding_num <= ret->outval_num)
		{
			ft_putstr(ret->outvalue);
			ret->chars_printed += ret->outval_num;
		}
	else
	{
		while (ret->padding_num--)
		{
			if (i < ret->outval_num)
				ft_putchar(ret->outvalue[i++]);
			else
				ft_putchar(ret->padding_type);
			ret->chars_printed += 1;
		}
	}
}

void	ft_rjf(t_printret *ret)
{
    int i;
    char    *s;

    i = 0;
	if (ret->padding_num <= ret->outval_num)
		{
			ft_putstr(ret->outvalue);
			ret->chars_printed += ret->outval_num;
		}
	else
	{
	    s = ret->outvalue;
	    if (ret->padding_type == 48 && (*s == '-' || *s == '+'))
        {
            ft_putchar(*s++);
            ret->chars_printed -= 1;
        }
        ret->padding_num = ret->padding_num - ret->outval_num;
        ret->chars_printed += (ret->padding_num - 1)+ ret->outval_num;
		while (ret->padding_num--)
		{
            ft_putchar(ret->padding_type);
			ret->chars_printed += 1;
		}
		ft_putstr(s);
	}
}

void	ft_display(t_printret *ret)
{
	ret->outval_num = ft_strlen(ret->outvalue);
	if (ret->padding_justify == -1)
		ft_ljf(ret);
	else
		ft_rjf(ret);
}
