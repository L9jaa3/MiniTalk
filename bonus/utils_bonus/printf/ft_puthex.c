#include "../../../minitalk_bonus.h"

int	ft_puthex(unsigned long num, char format, size_t *counter)
{
	char	*base;

	if (format == 'x')
		base = "0123456789abcdef";
	else if (format == 'X')
		base = "0123456789ABCDEF";
	if (num >= 16)
	{
		if (ft_puthex(num / 16, format, counter) == -1)
			return (-1);
	}
	if (ft_putchar(base[num % 16], counter) == -1)
		return (-1);
	return (0);
}
