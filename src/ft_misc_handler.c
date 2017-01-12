#include "ft_printf.h"

void	ft_conversions(t_printret *ret, va_list argp)
{
    int     i;
    char    *digits;

    i = 0;
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
    if (ret->format[ret->counter] == '.')
        ft_precision(ret, argp);
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
     if (ret->format[ret->counter] == '*')
    {
        ret->padding_num = ft_atoi(digits);
        ret->counter += 1;
    }
}

void	ft_precision(t_printret *ret, va_list argp)
{
    char    *digits;

    if (ft_isdigit(ret->format[ret->counter]))
    {
        digits = (char *)malloc(2);
        digits[0] = ret->format[ret->counter];
        digits[1] = '\0';
        ret->precision = ft_atoi(digits);
        ret->counter += 1;
    }
   // else  if (ret->format[ret->counter] == '*')
    //{
      //  ret->precision = ft_atoi(digits);
       // ret->counter += 1;
    //}
    else
        ret->precision = -1;
}
