#include "ft_printf.h"

void    ft_helper5(t_printret *ret, va_list argp)
{
    int     i;

    i = 0;
    if (ret->format[ret->counter] == 'X')
    {
		ret->outvalue = ft_itoa_basel(va_arg(argp, long), 16);
		if (ret->outvalue[0] != 48 && ret->hashable == 1)
		{
			ft_assigner(ret,"0x");
			ret->hashable = 0;
		}
        while (i < ft_strlen(ret->outvalue))
        {
            if (ft_isalpha(ret->outvalue[i]))
                ret->outvalue[i] = ft_toupper(ret->outvalue[i]);
            i +=1;
        }
    }
	if (ret->format[ret->counter] == 'x')
    {
		ret->outvalue = ft_itoa_basel(va_arg(argp, long), 16);
		if (ret->outvalue[0] != 48 && ret->hashable == 1)
		{
			ft_assigner(ret,"0x");
			ret->hashable = 0;
		}
    }
	if (ret->format[ret->counter] == 'o')
    {
		ret->outvalue = ft_itoa_basel(va_arg(argp, long), 8);
		if (ret->outvalue[0] != 48 && ret->hashable == 1)
		{
			ft_assigner(ret,"0");
			ret->hashable = 0;
		}
    }
}

void    ft_helper12(t_printret *ret, va_list argp)
{
	long	num;

    if (ret->format[ret->counter] == 'u')
	{
		num = va_arg(argp, unsigned long);
		ret->outvalue = ft_itoa(num);
	}
    else
        ft_helper5(ret, argp);
}

void    ft_handle_numb_long(t_printret *ret, va_list argp)
{
	long    num;

	num = 0;
	if (ret->format[ret->counter] == 'd' || ret->format[ret->counter] == 'i')
	{
		ret->outvalue = ft_ibase(va_arg(argp, long), 10);
		
		if (ret->forcepositive == 1 && ft_atoi(ret->outvalue) > 1)
		{
            ft_assigner(ret, "+");
			ret->forcepositive = 0;
		}
	}
	else
        ft_helper12(ret, argp);
    if (ret->outvalue)
    {
		if (!(ret->precision == -1 && ft_atoi(ret->outvalue)  == 0))
		{
    		ft_display(ret);
    		ret->isnumber = 1;
			ret->format += 1;
		}
		else
			ret->format += 1;
    }
	ret->outvalue = NULL;
	ret->outval_num = 0;
}
