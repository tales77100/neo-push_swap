/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:22:04 by jsantini          #+#    #+#             */
/*   Updated: 2025/11/10 11:37:42 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*final;

	if (nmemb <= 0 || size <= 0)
		return (malloc(0));
	if (size > 2147483647 || nmemb > 2147483647 || nmemb * size > 2147483647)
		return (NULL);
	final = malloc(sizeof(char) * (nmemb * size));
	if (!final)
		return (NULL);
	ft_bzero(final, nmemb * size);
	return (final);
}
/*
int	main(void)
{
	int *temp;
	int *temp1;
	int	i;

	temp = calloc(10, sizeof(int));
	temp1 = ft_calloc(10, sizeof(int));
	i = 0;
	while (i < 10)
	{
		temp[i] = 'a';
		i++;
	}
	i = 0;
	while (i < 10)
	{
		temp1[i] = 'a';
		i++;
	}
	free(temp);
	free(temp1);
	return (0);
}*/
