/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrast <rrast@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:53:55 by rrast             #+#    #+#             */
/*   Updated: 2022/02/02 10:59:45 by rrast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

void	ft_takestr(int signl, siginfo_t *siginfo, void *old)
{
	static char	c;
	static int	n;
	static int	pid;

	(void) old;
	if (!pid || (pid != siginfo->si_pid))
	{
		pid = siginfo->si_pid;
		c = 0;
		n = 1;
	}
	if (signl == SIGUSR1)
		c = c | n;
	n *= 2;
	if (n > 128)
	{
		write(1, &c, 1);
		c = 0;
		n = 1;
	}
	kill(siginfo->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sig;

	ft_printf("PID server: %d\n", getpid());
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = ft_takestr;
	if (sigaction(SIGUSR1, &sig, NULL) < 0 \
		|| sigaction(SIGUSR2, &sig, NULL) < 0)
	{
		ft_printf("Signal processing error.\n");
		exit (1);
	}
	while (1)
		pause();
	return (0);
}
