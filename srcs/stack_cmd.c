/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <jsantini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:09:04 by jsantini          #+#    #+#             */
/*   Updated: 2026/01/09 13:58:04 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*pop_item(t_list **head)
{
	t_list	*item;

	if (!head || !(*head))
		return (NULL);
	item = *head;
	*head = (*head)->next;
	item->next = NULL;
	return (item);
}

void	*push_list(t_list **head, t_list *new)
{
	if (!new)
		return (NULL);
	if (!*head)
	{
		*head = new;
		return (new);
	}
	new->next = *head;
	*head = new;
	return (new);
}

void	aff_lst(t_list *head)
{
	while (head)
	{
		ft_printf("|%d|\n", head->value);
		head = head->next;
	}
	return ;
}
