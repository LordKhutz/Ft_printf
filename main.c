#include <ft_printf.h>
#include <stdio.h>

int	main(void)
{
	char *s = "sdsdsdsdsd";

	//printf(" (%d)\n", ft_printf("%#x, %#X, %+010d, %p, %hhd, %lld, %lu", 42, 50, 99, &(s), 'a', 9223372036854775807, -42));
	//printf(" (%d)\n", printf("%#x, %#X, %+010d, %p, %hhd, %lld, %lu", 42, 50, 99, &(s), 'a', 9223372036854775807, -42));
	//printf(" (%d)\n",ft_printf("%+010.3d\n", 99));
	printf("%d\n", ft_printf("%016llx\n", &s));
	printf("%d\n", printf("%016llx\n", &s));
	printf("%d\n", ft_printf("%18c %s\n", 'C', s));
	printf("%d\n", printf("%18c %s\n", 'C', s));
	//printf("%S\n", L"Khuthadzo");
	return (0);
}
