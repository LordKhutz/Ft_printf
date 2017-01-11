#include <ft_printf.h>
#include <stdio.h>

int	main(void)
{
	printf(" (%d)\n", ft_printf("%s", "sdsdsds"));
	printf(" (%d)\n", printf("%d", 42));
	return (0);
}
