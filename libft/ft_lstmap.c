/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:26:12 by jsantini          #+#    #+#             */
/*   Updated: 2025/11/10 14:27:55 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;

	if (!lst)
		return (lst);
	head = ft_lstnew(*(int *)f(&lst->value));
	if (!head || ! head->value)
		return (NULL);
	while (lst->next != NULL)
	{
		if (!ft_lstlast(head) || !ft_lstlast(head)->value)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&head, ft_lstnew(*(int *)f(&lst->value)));
	}
	if (!ft_lstlast(head) || !ft_lstlast(head)->value)
	{
		ft_lstclear(&head, del);
		return (NULL);
	}
	return (head);
}
