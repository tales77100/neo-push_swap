/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <jsantini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:09:10 by jsantini          #+#    #+#             */
/*   Updated: 2026/01/08 15:09:12 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_list **a)
{
	t_list *temp;
	if (ft_lstsize(*a) < 2)
		return (0);
	temp = (*a)->next;
	(*a)->next = temp->next;
	temp->next = *a;
	*a = temp;
	return (1);
}

int	sb(t_list **b)
{
	t_list *temp;

	if (ft_lstsize(*b) < 2)
		return (0);
	temp = (*b)->next;
	(*b)->next = temp->next;
	temp->next = *b;
	*b = temp;
	ft_printf("sb\n");
	return (1);
}

