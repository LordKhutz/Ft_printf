#include <ft_printf.h>
#include <libc.h>

int	main(void)
{
	printf(" (%d)\n", ft_printf("%#X", 1));
	printf(" (%d)\n", printf("%#X\n", 1));
	return (0);
}
