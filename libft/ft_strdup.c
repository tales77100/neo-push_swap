/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:24:15 by jsantini          #+#    #+#             */
/*   Updated: 2025/11/05 11:24:24 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*final;
	int		i;

	final = malloc(sizeof(char) * (len(s) + 1));
	if (!final)
		return (final);
	i = 0;
	while (s[i])
	{
		final[i] = s[i];
		i++;
	}
	final[i] = '\0';
	return (final);
}
