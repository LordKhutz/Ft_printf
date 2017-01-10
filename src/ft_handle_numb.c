#include "ft_printf.h"

void    ft_helper2(t_printret *ret, va_list argp)
{
    int     i;
    
    i = 0;
    if (ret->format[ret->counter] == 'X')
    {
		ret->outvalue = ft_itoa_base(va_arg(argp, int), 16);
        while (i < ft_strlen(ret->outvalue))
        {
            if (ft_isalpha(ret->outvalue[i]))
                ret->outvalue[i] = ft_toupper(ret->outvalue[i]);
            i +=1;
        }
    }
	else if (ret->format[ret->counter] == 'x')
    {
		ret->outvalue = ft_itoa_base(va_arg(argp, int), 16);
    }
	else if (ret->format[ret->counter] == 'o')
    {
		ret->outvalue = ft_itoa_base(va_arg(argp, int), 8);
    }
}

void    ft_helper1(t_printret *ret, va_list argp)
{
	long	num;

    if (ret->format[ret->counter] == 'u')
	{
		num = va_arg(argp, unsigned int);
		ret->outvalue = ft_itoa(num);
	}
	else if (ret->format[ret->counter] == 'U')
	{
		num = va_arg(argp, unsigned long);
		ret->outvalue = ft_itoa(num);
	}
    else
        ft_helper2(ret, argp);
}

void    ft_handle_numb(t_printret *ret, va_list argp)
{
	long    num;

	num = 0;
	if (ret->format[ret->counter] == 'd' || ret->format[ret->counter] == 'i')
	{
		num = va_arg(argp, int);
		ret->outvalue = ft_itoa(num);
	}
	else if (ret->format[ret->counter] == 'D')
	{
		num = va_arg(argp, long);
		ret->outvalue = ft_itoa(num);
	}
	else
        ft_helper1(ret, argp);
    if (ret->outvalue)
    	ft_display(ret);
	ret->outvalue = NULL;
	ret->outval_num = 0;
}
