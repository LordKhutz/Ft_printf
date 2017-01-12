#include <ft_printf.h>
#include <stdio.h>

int	main(void)
{
	char *s = "sdsdsdsdsd";

	//printf(" (%d)\n", ft_printf("%#x, %#X, %+010d, %p, %hhd, %lld, %lu", 42, 50, 99, &(s), 'a', 9223372036854775807, -42));
	//printf(" (%d)\n", printf("%#x, %#X, %+010d, %p, %hhd, %lld, %lu", 42, 50, 99, &(s), 'a', 9223372036854775807, -42));
	printf(" (%d)\n",ft_printf("%+010.3d\n", 99));
	return (0);
}
