/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <jsantini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:08:40 by jsantini          #+#    #+#             */
/*   Updated: 2026/01/09 13:40:58 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_list **a, int act)
{
	t_list	*temp;
	t_list	*head;

	if (ft_lstsize(*a) < 2)
		return (0);
	temp = *a;
	*a = (*a)->next;
	head = *a;
	while (head && head->next)
		head = head->next;
	head->next = temp;
	temp->next = NULL;
	if (act != 1)
		ft_printf("ra\n");
	return (1);
}

int	rb(t_list **b, int act)
{
	t_list	*temp;
	t_list	*head;

	if (ft_lstsize(*b) < 2)
		return (0);
	temp = *b;
	*b = (*b)->next;
	head = *b;
	while (head && head->next)
		head = head->next;
	head->next = temp;
	temp->next = NULL;
	if (act != 1)
		ft_printf("rb\n");
	return (1);
}

int	rr(t_list **a, t_list **b)
{
	ra(a, 1);
	rb(b, 1);
	ft_printf("rr\n");
	return (1);
}
