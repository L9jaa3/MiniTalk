#include "../../../minitalk_bonus.h"

int	ft_putstr(char *str, size_t *counter)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		if (ft_putchar(*str, counter) == -1)
			return (-1);
		str++;
	}
	return (0);
}
