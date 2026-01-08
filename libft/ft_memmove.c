/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:23:49 by jsantini          #+#    #+#             */
/*   Updated: 2025/11/10 14:09:15 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*src_c;
	char	*dest_c;

	if (!dest && !src)
		return (NULL);
	src_c = (char *)src;
	dest_c = (char *)dest;
	if (dest_c > src_c)
	{
		i = n;
		while (i > 0)
		{
			dest_c[i - 1] = src_c[i - 1];
			i--;
		}
		return (dest_c);
	}
	i = 0;
	while (i < n)
	{
		dest_c[i] = src_c[i];
		i++;
	}
	return (dest_c);
}
