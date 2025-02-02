#include "../../../minitalk.h"

static int	ft_formatchecker(va_list ap, char formatSig, size_t *counter)
{
	if (formatSig == 'd' || formatSig == 'i')
		return (ft_putnbr(va_arg(ap, int), counter));
	else if (formatSig == 'c')
		return (ft_putchar(va_arg(ap, int), counter));
	else if (formatSig == 's')
		return (ft_putstr(va_arg(ap, char *), counter));
	else if (formatSig == 'x' || formatSig == 'X')
		return (ft_puthex(va_arg(ap, unsigned int), formatSig, counter));
	else if (formatSig == 'p')
		return (ft_putaddr(va_arg(ap, unsigned long), counter));
	else if (formatSig == 'u')
		return (ft_putunsigned(va_arg(ap, unsigned int), counter));
	else if (formatSig == '%')
		return (ft_putchar('%', counter));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	counter;
	int		checker;

	va_start(ap, format);
	counter = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break ;
			checker = ft_formatchecker(ap, *format, &counter);
		}
		else
			checker = ft_putchar(*format, &counter);
		if (checker == -1)
			return (va_end(ap), -1);
		format++;
	}
	va_end(ap);
	return (counter);
}
