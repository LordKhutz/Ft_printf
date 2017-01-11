#include "ft_printf.h"

char	*ft_assigner(t_printret	*ret, char *s)
{
	char	*helpvar;
	int		i;
	int     j;

	i = 0;
	j = 0;
	helpvar = (char *)malloc(ft_strlen(ret->outvalue) + ft_strlen(s));
	while (i < (ft_strlen(ret->outvalue) + ft_strlen(s)))
	{
	    while (j < ft_strlen(s))
            helpvar[i++] = s[j++];
        j = 0;
        while (j < ft_strlen(ret->outvalue))
            helpvar[i++] = ret->outvalue[j++];
		i += 1;
	}
	helpvar[i - 1] = '\0';
	return (helpvar);
}

void	ft_helper3(t_printret *ret, va_list argp)
{
	if (ret->format[ret->counter] == 'p')
	{
		ret->outvalue = ft_strcat("0x",
			ft_itoa_base((unsigned long)va_arg(argp, long), 16));
	}
}

void    ft_helper2(t_printret *ret, va_list argp)
{
    int     i;

    i = 0;
    if (ret->format[ret->counter] == 'X')
    {
		ret->outvalue = ft_itoa_base(va_arg(argp, int), 16);
		if (ret->outvalue[0] != 48 && ret->hashable == 1)
		{
			ret->outvalue  = ft_assigner(ret,"0x");
			ret->hashable = 0;
		}
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
		if (ret->outvalue[0] != 48 && ret->hashable == 1)
		{
			ret->outvalue  = ft_assigner(ret,"0x");
			ret->hashable = 0;
		}
    }
	else if (ret->format[ret->counter] == 'o')
    {
		ret->outvalue = ft_itoa_base(va_arg(argp, int), 8);
		if (ret->outvalue[0] != 48 && ret->hashable == 1)
		{
			ret->outvalue  = ft_assigner(ret,"0");
			ret->hashable = 0;
		}
    }
	else
		ft_helper3(ret, argp);
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
		if (ret->forcepositive == 1 && num > 1)
            ret->outvalue = ft_assigner(ret,"+");
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
    ret->format += 1;
	ret->outvalue = NULL;
	ret->outval_num = 0;
}
