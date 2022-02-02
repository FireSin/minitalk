/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrast <rrast@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:02:59 by rrast             #+#    #+#             */
/*   Updated: 2022/02/02 10:36:32 by rrast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

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
		usleep(150);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		pid;
	int		a;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	a = 0;
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
