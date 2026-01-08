/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:26:24 by jsantini          #+#    #+#             */
/*   Updated: 2026/01/08 12:29:10 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*make_list(char **v)
{
	int	i;
	t_list	*final;

	final = NULL;
	while (*(++v))
	{
		i = -1;
		while ((*v)[++i])
			if (ft_isdigit((*v)[i]) == 0)
				return (ft_lstclear(&final, &free));
		if (!final)
			final = ft_lstnew(ft_atoi(*v));
		else
			ft_lstadd_back(&final, ft_lstnew(ft_atoi(*v)));
	}
	return (final);
}

int	main(int i, char **v)
{
	if (i < 1)
		return (0);
	//if (i == 2)
		//algo(make_list_one(v[1]));
	//else
	algo(make_list(v));
}
