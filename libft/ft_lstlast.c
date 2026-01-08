/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:27:37 by jsantini          #+#    #+#             */
/*   Updated: 2025/11/10 09:27:43 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*final;

	if (!lst)
		return (lst);
	final = lst;
	while (final->next != NULL)
		final = final->next;
	return (final);
}
/*
int	main(void)
{
	t_list * l =  NULL;

	if (ft_lstlast(l) == 0)
		printf("1\n");
	ft_lstadd_back(&l, ft_lstnew((void*)1));
	if (ft_lstlast(l)->content == (void*)1)
		printf("2\n");
	ft_lstadd_back(&l, ft_lstnew((void*)2));
	if (ft_lstlast(l)->content == (void*)2)
		printf("3\n");
	if (ft_lstlast(l)->next == 0)
		printf("4\n");
}*/
