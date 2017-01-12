#include "ft_printf.h"

char	*ft_itoa_base(unsigned int numb, int base)
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

char	*ft_itoa_bases(unsigned short numb, int base)
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

char	*ft_itoa_basel(unsigned long numb, int base)
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

char	*ft_ibase(long numb, int base)
{
	static char		rep[16] = "0123456789abcdef";
	static char		buff[65];
	char			*ptr;
	unsigned long	neg;

	ptr = &buff[64];
	*ptr = '\0';
	neg = numb;
	if (numb < 0)
		neg = -(numb);
	else
		neg = numb;
	if (numb == 0)
		*--ptr = rep[neg % base];
	while (neg != 0)
	{
		*--ptr = rep[neg % base];
		neg /= base;
	}
	if (numb < 0)
		*--ptr = '-';
	return (ptr);
}

char	*ft_ibases(short numb, int base)
{
	static char		rep[16] = "0123456789abcdef";
	static char		buff[65];
	char			*ptr;
	unsigned long	neg;

	ptr = &buff[64];
	*ptr = '\0';
	neg = numb;
	if (numb < 0)
		neg = -(numb);
	else
		neg = numb;
	if (numb == 0)
		*--ptr = rep[neg % base];
	while (neg != 0)
	{
		*--ptr = rep[neg % base];
		neg /= base;
	}
	if (numb < 0)
		*--ptr = '-';
	return (ptr);
}
