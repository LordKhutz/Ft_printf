#include <ft_printf.h>
#include <libc.h>

int	main(void)
{
	printf("%d\n", ft_printf("%jx\n",4294967295));
	printf("%d\n", printf("%jx", 4294967295));
	return (0);
}
