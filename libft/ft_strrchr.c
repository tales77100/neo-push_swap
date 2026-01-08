/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:25:07 by jsantini          #+#    #+#             */
/*   Updated: 2025/11/06 12:23:08 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int				len_s;
	unsigned char	temp;

	len_s = len((char *)s);
	temp = (unsigned char)c;
	while (len_s > 0 && (unsigned char)s[len_s] != temp)
		len_s--;
	if (s[len_s] == temp)
		return ((char *)(s + len_s));
	return (NULL);
}
