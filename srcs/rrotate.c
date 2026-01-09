/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <jsantini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:08:57 by jsantini          #+#    #+#             */
/*   Updated: 2026/01/08 15:08:58 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_list **a)
{
	t_list	*head;
	t_list	*temp;

	if (ft_lstsize(*a) < 2)
		return (0);
	head = *a;
	while (head && head->next && head->next->next)
		head = head->next;
	if (head->next && head->next->next)
	{
		temp = head->next->next;
		head->next->next = NULL;
	}
	else
	{
		temp = head->next;
		head->next = NULL;
	}
	temp->next = *a;
	*a = temp;
	ft_printf("rra\n");
	return (1);
}

int	rrb(t_list **b)
{
	t_list	*head;
	t_list	*temp;

	if (ft_lstsize(*b) < 2)
		return (0);
	head = *b;
	while (head && head->next && head->next->next)
		head = head->next;
	if (head->next && head->next->next)
	{
		temp = head->next->next;
		head->next->next = NULL;
	}
	else
	{
		temp = head->next;
		head->next = NULL;
	}
	temp->next = *b;
	*b = temp;
	ft_printf("rrb\n");
	return (1);
}
