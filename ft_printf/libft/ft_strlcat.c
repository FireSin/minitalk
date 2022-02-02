/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrast <rrast@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:57:35 by rrast             #+#    #+#             */
/*   Updated: 2021/10/12 12:37:06 by rrast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		lendst;
	size_t		lensrc;

	i = 0;
	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	if (dstsize <= lendst)
		return (lensrc + dstsize);
	if (dstsize)
	{
		while (src[i] && lendst < dstsize - 1)
		{
			dst[lendst] = src[i];
			lendst++;
			i++;
		}
		dst[lendst] = '\0';
	}
	return (lendst + lensrc - i);
}
