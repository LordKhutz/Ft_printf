#include <ft_printf.h>
#include <stdio.h>

int	main(void)
{
	char *s = "sdsdsdsdsd";

	printf(" (%d)\n", ft_printf("%#x, %#X, %+010d, %p, %hhd", 42, 50, 99, &(s), 256));
	printf(" (%d)\n", printf("%#x, %#X, %+010d, %p, %hhd", 42, 50, 99, &(s), 130));
	printf(" (%d)\n",ft_printf("@moulitest: %s", "Khuthadzo"));
	return (0);
}
