/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:24:24 by jsantini          #+#    #+#             */
/*   Updated: 2025/11/05 09:24:28 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	j;
	int		final;

	if (siz <= (size_t)len(dst))
		return (siz + len((char *)src));
	i = len(dst);
	j = 0;
	final = len(dst) + len((char *)src);
	while (src[j] && i < siz - 1)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (final);
}
