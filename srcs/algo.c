/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:29:24 by jsantini          #+#    #+#             */
/*   Updated: 2026/01/08 12:29:39 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *pop_item(t_list **head)
{
	t_list *item;

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

int	pb(t_list **a, t_list **b)
{
	if (push_list(b, pop_item(a)) == NULL)
		return (-1);
	ft_printf("pb\n");
	return (1);	
}

int	pa(t_list **a, t_list **b)
{
	if (push_list(a, pop_item(b)) == NULL)
		return (-1);
	ft_printf("pa\n");
	return (1);	
}

void	algo(t_list *a)
{
	t_list *b[1];

	*b = NULL;
	pb(&a, b);
	ft_printf("\n a\n |\n v\n");
	aff_lst(a);
	ft_printf("\n b\n |\n v\n");
	aff_lst(*b);
	pb(&a, b);
	ft_printf("\n a\n |\n v\n");
	aff_lst(a);
	ft_printf("\n b\n |\n v\n");
	aff_lst(*b);
	while (*b)
		pa(&a, b);
	ft_printf("\n a\n |\n v\n");
	aff_lst(a);
	ft_printf("\n b\n |\n v\n");
	aff_lst(*b);
	return ;
}
