/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrast <rrast@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:33:08 by rrast             #+#    #+#             */
/*   Updated: 2021/10/21 17:32:02 by rrast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*delt;

	while (*lst)
	{
		if ((*lst)->content)
			del((*lst)->content);
		delt = *lst;
		*lst = delt->next;
		free(delt);
	}
	lst = NULL;
}
