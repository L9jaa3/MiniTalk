#include "../../../minitalk.h"

int	ft_putunsigned(unsigned int n, size_t *counter)
{
	if (n >= 10)
	{
		if (ft_putunsigned(n / 10, counter) == -1)
			return (-1);
	}
	if (ft_putchar((n % 10) + '0', counter) == -1)
		return (-1);
	return (0);
}
