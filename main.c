#include <ft_printf.h>
#include <stdio.h>

int	main(void)
{
	printf(" (%d)\n", ft_printf("%#x, %#X, %+010d,", 42, 50, 99));
	printf(" (%d)\n", printf("%#x, %#X, %+010d,", 42, 50, 99));
	return (0);
}
