#include "ft_printf.h"

void		handle_length(va_list argp, t_printret *ret)
{
    if (ret->format[ret->counter] == 'h')
    {
        ret->counter += 1;
        if (ret->format[ret->counter] == 'h')
        {
            ret->counter += 1;
            ft_handle_numb(ret, argp);
        }
        else
            ft_handle_numb_short(ret, argp);
    }
    if (ret->format[ret->counter] == 'l')
    {
        ret->counter += 1;
        if (ret->format[ret->counter] == 'l')
        {
            ret->counter += 1;
            ft_handle_numb_llong(ret, argp);
        }
        else
            ft_handle_numb_long(ret, argp);
    }
    if (ret->format[ret->counter] == 'j')
    {
        ret->counter += 1;
        ft_handle_numb_intmax(ret, argp);
    }
    if (ret->format[ret->counter] == 'z')
    {
        ret->counter += 1;
        ft_handle_numb_sizet(ret, argp);
    }
}
