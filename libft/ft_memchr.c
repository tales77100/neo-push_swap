/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:22:55 by jsantini          #+#    #+#             */
/*   Updated: 2025/11/14 09:36:01 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char *)s;
	if (n == 0)
		return (NULL);
	while (*temp != (unsigned char)c && i < n - 1)
	{
		temp++;
		i++;
	}
	if (*temp == (unsigned char)c)
		return (temp);
	return (NULL);
}
/*
int	main()
{
	char buff[] = "abc";
	char buff1[] = "abc";
	char	*temp;
	char	*temp1;

	temp = memchr(buff, 'b', 3);
	temp1 = ft_memchr(buff1, 'b', 3);
	return (0);
}*/
