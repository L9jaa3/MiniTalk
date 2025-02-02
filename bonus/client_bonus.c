#include "../minitalk_bonus.h"

static pid_t	g_pid;

void	send_signal(int pid, char c)
{
	int	j;

	j = 0;
	while (j++ < 8)
	{
		if (((c >> (8 - j)) & 1) == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(200);
		usleep(200);
	}
}

void	connection(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (signum == SIGUSR2 && info->si_pid == g_pid)
		ft_printf("Done , all bytes received successfully");
}

int	main(int argc, char **argv)
{
	struct sigaction	client;
	int					i;

	if (argc != 3 || ft_atoi(argv[1]) == 0)
	{
		ft_printf("error : ./client [PID] [ARG]\n");
		return (0);
	}
	i = 0;
	g_pid = ft_atoi(argv[1]);
	client.sa_sigaction = connection;
	client.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &client, 0);
	sigaction(SIGUSR1, &client, 0);
	while (argv[2][i])
	{
		send_signal(g_pid, argv[2][i]);
		i++;
	}
	send_signal(g_pid, '\0');
}
