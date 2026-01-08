/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:30:31 by jsantini          #+#    #+#             */
/*   Updated: 2025/11/10 09:30:33 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	final = malloc(sizeof(char) * (len(s1) + len(s2) + 1));
	if (!final)
		return (final);
	i = 0;
	while (*s1)
		final[i++] = *(s1++);
	while (*s2)
		final[i++] = *(s2++);
	final[i] = '\0';
	return (final);
}
