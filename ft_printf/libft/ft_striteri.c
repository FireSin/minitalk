/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrast <rrast@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:39:56 by rrast             #+#    #+#             */
/*   Updated: 2021/10/18 13:44:53 by rrast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	l;
	size_t	i;

	i = 0;
	if (s == 0)
		return ;
	l = ft_strlen(s);
	while (i < l)
	{
		(*f)(i, &s[i]);
		i++;
	}
}
