/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:21:57 by jsantini          #+#    #+#             */
/*   Updated: 2025/11/06 14:17:48 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = (char *)s;
	while (i < n)
	{
		*temp = 0;
		temp++;
		i++;
	}
}
/*
int	main(void)
{
	char buff[] = "salut";
	char	buff1[] = "salut";

	bzero(buff, 5);
	ft_bzero(buff1, 5);
	return (0);
}*/
