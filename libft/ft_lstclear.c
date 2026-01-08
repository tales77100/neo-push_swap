/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:13:45 by jsantini          #+#    #+#             */
/*   Updated: 2025/11/10 14:22:39 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!*lst || !lst)
		return (NULL);
	while ((*lst)->next != NULL)
	{
		temp = *lst;
		*lst = (*lst)->next;
		del(temp);
	}
	del(*lst);
	*lst = NULL;
	return (NULL);
}
