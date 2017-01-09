#include <ft_printf.h>
#include <libc.h>

int	main(void)
{
	printf("%d\n", ft_printf("%d\n", 42));
	printf("%d\n", printf("%+d\n", 42));
	return (0);
}
