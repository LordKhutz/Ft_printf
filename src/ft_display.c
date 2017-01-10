#include "ft_printf.h"

void	ft_ljf(t_printret *ret)
{
	if (ret->padding_num <= ret->outval_num)
		{
			ft_putstr(ret->outvalue);
			ret->chars_printed += ret->outval_num;
		}
	else
	{
		while (ret->padding_num--)
		{
			if (ret->counter < ret->outval_num)
				ft_putchar(ret->outvalue[ret->counter++]);
			else
				ft_putchar(ret->padding_type);
			ret->chars_printed += 1;
		}
	}
}

void	ft_rjf2(t_printret *ret)
{
	int i;
	int j;

	i = ret->padding_num - ret->outval_num;
	j = 0;
	ret->padding_num -= i;
	while (j++ < i)
	{
		ft_putchar(ret->padding_type);
		ret->chars_printed += 1;
	}
	while (ret->padding_num--)
	{
		ft_putchar(ret->outvalue[ret->counter++]);
		ret->chars_printed += 1;
	}
}

void	ft_rjf(t_printret *ret)
{
	if (ret->outvalue[ret->counter] == '-')
	{
		ft_putchar(ret->outvalue[ret->counter++]);
	}
		ret->chars_printed += 1;
		if (ret->padding_num <= ret->outval_num)
		{
			while (ret->padding_num--)
			{
				ft_putchar(ret->outvalue[ret->counter++]);
				ret->chars_printed += 1;
			}
		}
		else
		{
			ft_rjf2(ret);
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
