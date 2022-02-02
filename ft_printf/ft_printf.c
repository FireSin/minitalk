/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrast <rrast@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:20:02 by rrast             #+#    #+#             */
/*   Updated: 2021/11/22 11:34:27 by rrast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkarg(char arg, va_list ap)
{
	int	i;

	i = 0;
	if (arg == 'c')
	{
		ft_putchar_fd(va_arg(ap, int), 1);
		i = 1;
	}
	if (arg == 'd' || arg == 'i')
		i = ft_putnbr_fd(va_arg(ap, int), 1);
	if (arg == 's')
		i = ft_putstr_fd(va_arg(ap, char *), 1);
	if (arg == '%')
	{
		write (1, "%", 1);
		i = 1;
	}
	if (arg == 'u')
		i = ft_putnbr_unsign_fd(va_arg(ap, unsigned int), 1);
	if (arg == 'x' || arg == 'X')
		i = ft_putnbr_hex_fd(va_arg(ap, unsigned int), 1, arg);
	if (arg == 'p')
		i = ft_putnbr_hex_p_fd((unsigned long int)(va_arg(ap, void *)), 1, arg);
	return (i);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	int		k;

	i = 0;
	k = 0;
	va_start(ap, fmt);
	while ((char)fmt[i])
	{
		if ((char)fmt[i] == '%')
		{
			i++;
			k = k + ft_checkarg((char)fmt[i], ap);
		}
		else
		{
			write(1, &fmt[i], 1);
			k++;
		}
		i++;
	}
	va_end(ap);
	return (k);
}
