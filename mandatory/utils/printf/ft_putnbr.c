#include "../../../minitalk.h"

int	ft_putnbr(int num, size_t *counter)
{
	if (num == -2147483648)
		return (ft_putstr("-2147483648", counter));
	if (num < 0)
	{
		if (ft_putchar('-', counter) == -1)
			return (-1);
		return (ft_putnbr(-num, counter));
	}
	if (num > 9)
	{
		if (ft_putnbr(num / 10, counter) == -1)
			return (-1);
	}
	if (ft_putchar((num % 10) + '0', counter) == -1)
		return (-1);
	return (0);
}
