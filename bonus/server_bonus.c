#include "../minitalk_bonus.h"

int	unicode_handler(unsigned char c)
{
	if (c < 0x80)
		return (1);
	else if ((c & 0xe0) == 0xc0)
		return (2);
	else if ((c & 0xf0) == 0xe0)
		return (3);
	else if ((c & 0xf8) == 0xf0)
		return (4);
	return (0);
}

int	check_bytes(int *counter, char *result, int *pid, int *index)
{
	static unsigned char	unicode[8];
	static int				bytes_num;

	if (++(*counter) == 8)
	{
		if (*index == 0)
			bytes_num = unicode_handler(*result);
		unicode[(*index)++] = *result;
		if (--bytes_num == 0)
		{
			unicode[*index] = '\0';
			ft_printf("%s", unicode);
			*index = 0;
		}
		if (*result == '\0')
		{
			kill(*pid, SIGUSR2);
			ft_printf("\n");
		}
		*counter = 0;
		*result = 0;
	}
	return (0);
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int		counter;
	static char		result;
	static pid_t	pid;
	static int		index;

	(void)context;
	if (info->si_pid != pid)
	{
		pid = info->si_pid;
		counter = 0;
		result = 0;
		index = 0;
	}
	if (signum == SIGUSR2)
		result |= (0b10000000 >> counter);
	check_bytes(&counter, &result, &pid, &index);
}

int	main(void)
{
	struct sigaction	server;
	pid_t				pid;

	pid = getpid();
	ft_printf("Server PID : %d \n", pid);
	server.sa_sigaction = signal_handler;
	server.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &server, 0);
	sigaction(SIGUSR2, &server, 0);
	while (1)
		pause();
	return (0);
}
