/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <jsantini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:08:30 by jsantini          #+#    #+#             */
/*   Updated: 2026/01/08 15:08:33 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

