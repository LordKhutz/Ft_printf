#include "ft_printf.h"

void	ft_conversions(t_printret *ret)
{
    if (ret->format[ret->counter] == '#')
    {
        ret->hashable = 1;
        ret->counter += 1;
    }
}
