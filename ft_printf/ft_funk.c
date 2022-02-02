/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrast <rrast@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:43:49 by rrast             #+#    #+#             */
/*   Updated: 2021/11/22 11:11:10 by rrast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsign_fd(unsigned int n, int fd)
{
	unsigned long int	k;
	int					i;
	int					a;

	k = 0;
	i = 0;
	while (n)
	{
		k = (k * 10) + (n % 10);
		n = n / 10;
		i++;
	}
	if (i == 0)
		write(1, "0", 1);
	a = i;
	while (i > 0)
	{
		ft_putchar_fd((k % 10) + 48, fd);
		k = k / 10;
		i--;
	}
	if (a == 0)
		a++;
	return (a);
}
