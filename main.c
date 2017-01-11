#include <ft_printf.h>
#include <libc.h>

int	main(void)
{
	printf(" (%d)\n", ft_printf("%#x, %#X", 42, 42));
	printf(" (%d)\n", printf("%#x, %#X", 42, 42));
	//printf(" (%d)\n", printf("%s\n", "Khuthadzo"));
	return (0);
}
