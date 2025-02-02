#include "../../../minitalk.h"

int	ft_putchar(char c, size_t *counter)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	(*counter)++;
	return (0);
}
