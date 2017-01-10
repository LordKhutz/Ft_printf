#include "ft_printf.h"

char	*ft_itoa_base(unsigned long numb, int base)
{
	static char		rep[16] = "0123456789abcdef";
	static char		buff[65];
	char			*ptr;
	unsigned long	neg;

	ptr = &buff[64];
	*ptr = '\0';
	neg = numb;
	if (numb == 0)
		*--ptr = rep[neg % base];
	while (neg != 0)
	{
		*--ptr = rep[neg % base];
		neg /= base;
	}
	return (ptr);
}
