/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrast <rrast@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:57:22 by rrast             #+#    #+#             */
/*   Updated: 2021/10/11 20:15:42 by rrast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*a;

	i = 0;
	c = c % 256;
	a = (char *) s;
	while (a[i] && a[i] != c)
		i++;
	if (a[i] == c)
		return (&a[i]);
	return (NULL);
}
