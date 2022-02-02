/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funk2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrast <rrast@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:59:33 by rrast             #+#    #+#             */
/*   Updated: 2021/11/22 11:13:50 by rrast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printhex_upper(int x)
{
	if (x == 10)
		write(1, "A", 1);
	if (x == 11)
		write(1, "B", 1);
	if (x == 12)
		write(1, "C", 1);
	if (x == 13)
		write(1, "D", 1);
	if (x == 14)
		write(1, "E", 1);
	if (x == 15)
		write(1, "F", 1);
}

void	ft_printhex_lower(int x)
{
	if (x == 10)
		write(1, "a", 1);
	if (x == 11)
		write(1, "b", 1);
	if (x == 12)
		write(1, "c", 1);
	if (x == 13)
		write(1, "d", 1);
	if (x == 14)
		write(1, "e", 1);
	if (x == 15)
		write(1, "f", 1);
}

void	ft_printhex(int i, unsigned long int k, char a, int fd)
{
	unsigned long int	x;

	x = 0;
	if (a == 'p')
		write(1, "0x", 2);
	if (i == 0)
		write(1, "0", 1);
	while (i > 0)
	{
		x = (k % 16);
		if (x > 9)
		{
			if (a == 'X')
				ft_printhex_upper(x);
			else
				ft_printhex_lower(x);
		}
		else
			ft_putchar_fd((k % 16) + 48, fd);
		k = k / 16;
		i--;
	}
}

int	ft_putnbr_hex_fd(unsigned int n, int fd, char a)
{
	unsigned long int	k;
	int					i;

	k = 0;
	i = 0;
	while (n)
	{
		k = (k * 16) + (n % 16);
		n = n / 16;
		i++;
	}
	ft_printhex(i, k, a, fd);
	if (i == 0)
		i++;
	if (a == 'p')
		i = i + 2;
	return (i);
}

int	ft_putnbr_hex_p_fd(unsigned long int n, int fd, char a)
{
	unsigned long int	k;
	int					i;

	k = 0;
	i = 0;
	while (n)
	{
		k = (k * 16) + (n % 16);
		n = n / 16;
		i++;
	}
	ft_printhex(i, k, a, fd);
	if (i == 0)
		i++;
	if (a == 'p')
		i = i + 2;
	return (i);
}
