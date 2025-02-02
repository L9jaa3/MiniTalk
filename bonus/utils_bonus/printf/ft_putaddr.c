#include "../../../minitalk_bonus.h"

int	ft_putaddr(unsigned long n, size_t *counter)
{
	if (ft_putstr("0x", counter) == -1)
		return (-1);
	return (ft_puthex(n, 'x', counter));
}
