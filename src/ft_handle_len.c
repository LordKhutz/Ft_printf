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
}
