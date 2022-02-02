/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrast <rrast@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:02:59 by rrast             #+#    #+#             */
/*   Updated: 2022/02/02 11:10:56 by rrast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

void	ft_takesig(int signl, siginfo_t *siginfo, void *old)
{
	(void) old;
	ft_printf("The signal has been successfully \
sent to the server with PID %d.\n", siginfo->si_pid);
}

int	ft_chartobite(char c, int n, int pid)
{
	while (n < 256)
	{
		if (c & n)
		{
			if (kill(pid, SIGUSR1) < 0)
				return (1);
		}
		else
		{
			if (kill(pid, SIGUSR2) < 0)
				return (1);
		}
		n *= 2;
		usleep(100);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	struct sigaction	sig;
	int					pid;
	int					a;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	a = 0;
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = ft_takesig;
	if (sigaction(SIGUSR1, &sig, NULL) < 0)
	{
		ft_printf("Signal processing error.\n");
		exit (1);
	}
	while (argv[2][a])
	{
		if (ft_chartobite(argv[2][a++], 1, pid))
		{
			ft_printf("Signal sending error or wrong PID.\n");
			break ;
		}
	}		
	return (0);
}
