/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <jsantini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:09:10 by jsantini          #+#    #+#             */
/*   Updated: 2026/01/09 13:58:53 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_list **a, int act)
{
	t_list	*temp;

	if (ft_lstsize(*a) < 2)
		return (0);
	temp = (*a)->next;
	(*a)->next = temp->next;
	temp->next = *a;
	*a = temp;
	if (act != 1)
		ft_printf("sa\n");
	return (1);
}

int	sb(t_list **b, int act)
{
	t_list	*temp;

	if (ft_lstsize(*b) < 2)
		return (0);
	temp = (*b)->next;
	(*b)->next = temp->next;
	temp->next = *b;
	*b = temp;
	if (act != 1)
		ft_printf("sb\n");
	return (1);
}

int	ss(t_list **a, t_list **b)
{
	sa(a, 1);
	sb(b, 1);
	ft_printf("ss\n");
	return (1);
}
