/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:29:24 by jsantini          #+#    #+#             */
/*   Updated: 2026/01/19 12:43:35 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	aff(t_list *a, t_list *b)
{
	ft_printf("----------a-----------\n");
	aff_lst(a);
	ft_printf("----------b-----------\n");
	aff_lst(b);

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


void	sort_three(t_list **h)
{
	int	top;
	int	mid;
	int	bas;

	top = (*h)->value;
	mid = (*h)->next->value;
	bas = (*h)->next->next->value;

	if (top > mid && top > bas)
		ra(h, 0);
	else if (mid > top && mid > bas)
		rra(h, 0);
	top = (*h)->value;
	mid = (*h)->next->value;
	if (top > mid)
		sa(h, 0);
	return ;
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

int	is_sort(t_list *head)
{
	while (head->next && head->value < head->next->value)
		head = head->next;
	if (!(head->next))
		return (1);
	return (0);
}

void	second_sort(t_list **a, t_list **b, int max, int i)
{
	int	s;

	s = ft_lstsize(*b);
	while (s-- && i <= max && is_sort(*a) == 0)
	{
		if ((((*b)->index_sort >> i) & 1) == 0)
			rb(b, 0);
		else
			pa(a, b);
	}
	if (is_sort(*a) == 1)
		while (*b)
			pa(a, b);

}

void	sorting(t_list **a, t_list **b)
{
	int i;
	int size;
	int max_bits;

	size = ft_lstsize(*a);
	max_bits = get_max_byte(*a);
	i = 0;
	while (i <= max_bits)
	{
		size = ft_lstsize(*a);
		while (size-- && is_sort(*a) == 0)
		{
			if ((((*a)->index_sort >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a, 0);
		}
		i++;
		second_sort(a, b, max_bits, i);
	}
	while (*b)
		pa(a, b);
}

void	sort_five(t_list **a, t_list **b)
{
	t_list	*max;

	while (ft_lstsize(*a) > 3)
	{
		get_price(*a);
		max = highest_in_stack(*a);
		while (max != *a)
		{
			if (max->place > max->size / 2)
				rra(a, 0);
			else
				ra(a, 0);
		}
		pb(a, b);
	}
	sort_three(a);
	pa(a, b);
	ra(a, 0);
	pa(a, b);
	ra(a, 0);

}

void	algo(t_list *a)
{
	t_list *b[1];
	int	size_l;

	*b = NULL;
	if (!a)
		return ;
	get_target(a);
	size_l = ft_lstsize(a);
	if (size_l == 1 || is_sort(a))
		return ;
	if (size_l == 2 && a->value > a->next->value)
		return ((void)sa(&a, 0));
	else if (size_l == 2)
		return ;
	if (size_l == 3)
		return (sort_three(&a));
	if (size_l == 5)
		return (sort_five(&a, b));
	index_stack(a);
	sorting(&a, b);
	//aff(a, *b);
	ft_lstclear(&a, &free);
	return ;
}
