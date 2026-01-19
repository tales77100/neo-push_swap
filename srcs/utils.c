/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 13:37:57 by jsantini          #+#    #+#             */
/*   Updated: 2026/01/19 13:38:56 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(t_list *head)
{
	while (head->next && head->value < head->next->value)
		head = head->next;
	if (!(head->next))
		return (1);
	return (0);
}

void	index_stack(t_list *a)
{
	int	i;

	get_price(a);
	while (a->target->value > a->value)
		a = a->target;
	i = 0;
	a->index_sort = a->size - 1;
	a = a->target;
	while (a->target->value > a->value)
	{
		a->index_sort = i;
		a = a->target;
		i++;
	}
}

t_list	*highest_in_stack(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (head)
	{
		if (temp->value < head->value)
			temp = head;
		head = head->next;
	}
	return (temp);
}

int	get_max_byte(t_list *head)
{
	int	i_max;
	int	i;

	if (!head)
		return (0);
	i_max = highest_in_stack(head)->index_sort;
	i = 0;
	while ((i_max >> i) != 0)
		i++;
	return (i);
}
