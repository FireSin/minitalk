/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrast <rrast@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:56:51 by rrast             #+#    #+#             */
/*   Updated: 2021/10/11 17:28:42 by rrast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < (n - 1))
	{
		if (((unsigned char *) s1)[i] != ((unsigned char *) s2)[i])
			break ;
		i++;
	}
	return (((unsigned char *) s1)[i] - ((unsigned char *) s2)[i]);
}
