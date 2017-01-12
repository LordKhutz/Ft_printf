#include "ft_printf.h"

void	ft_conversions(t_printret *ret, va_list argp)
{
    int     i;
    char    *digits;

    i = 0;
    if (ret->format[ret->counter] == '%')
    {
        ret->counter += 1;
        ret->outvalue = "%\0";
        ft_display(ret);
    }
    if (ret->format[ret->counter] == '#')
    {
        ret->hashable = 1;
        ret->counter += 1;
    }
    if (ret->format[ret->counter] == '+')
    {
        ret->forcepositive = 1;
        ret->counter += 1;
    }
    if (ret->format[ret->counter] == '-')
    {
        ret->padding_justify = -1;
        ret->counter += 1;
    }
    if (ret->format[ret->counter] == '0')
    {
        ret->padding_type = 48;
        ret->counter += 1;
    }
    if (ret->format[ret->counter] == ' ')
    {
        ret->padding_type = ' ';
        ret->counter += 1;
    }
    if (ft_isdigit(ret->format[ret->counter]) && !(ft_isalpha(ret->format[ret->counter])))
    {
        
        while (ft_isdigit(ret->format[ret->counter]) && !(ft_isalpha(ret->format[ret->counter])))
        {
            i += 1;
            ret->counter += 1;
        }
        ret->counter -= i;
        digits = (char *)malloc(i);
        i = 0;
        while (ft_isdigit(ret->format[ret->counter]) && !(ft_isalpha(ret->format[ret->counter])))
        {
            digits[i++] = ret->format[ret->counter];
            ret->counter += 1;
        }
        digits[i] = '\0';
        ret->padding_num = ft_atoi(digits);
    }
    if (ret->format[ret->counter] == '.' && !(ft_isalpha(ret->format[ret->counter])))
        ft_precision(ret, argp);
}

void	ft_precision(t_printret *ret, va_list argp)
{
    char    *digits;
    int     i;

    i = 0;
    if (ft_isdigit(ret->format[ret->counter]) && !(ft_isalpha(ret->format[ret->counter])))
    {
        while (ft_isdigit(ret->format[ret->counter]) && !(ft_isalpha(ret->format[ret->counter])))
        {
            i += 1;
            ret->counter += 1;
        }
        ret->counter -= i;
        digits = (char *)malloc(i);
        i = 0;
        while (ft_isdigit(ret->format[ret->counter]) && !(ft_isalpha(ret->format[ret->counter])))
        {
            digits[i++] = ret->format[ret->counter];
            ret->counter += 1;
        }
        digits[i] = '\0';
        ret->precision = ft_atoi(digits);
        if (ret->precision == 0)
         ret->precision = -1;
    }
    //else
    //{
      //  ret->precision = -1;
       // ret->counter += 1;
    //}
}
