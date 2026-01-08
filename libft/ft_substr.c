/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:38:41 by jsantini          #+#    #+#             */
/*   Updated: 2025/11/10 11:38:30 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_s(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*make_empty(void)
{
	char	*temp;

	temp = malloc(1);
	if (!temp)
		return (temp);
	temp[0] = '\0';
	return (temp);
}

static int	abs_int(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (start > (unsigned int)len_s((char *)s) || len == 0)
		return (make_empty());
	if (len >= len_s((char *)s) - start)
		sub = malloc(sizeof(char) * (len_s((char *)s) - start + 1));
	else
		sub = malloc(sizeof(char) * (abs_int((int)len) + 1));
	if (!sub)
		return (NULL);
	while (i < len && s[i + start])
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
/*
int	main(void)
{
	char	str[] = "lorem ipsum dolor sit amet";
	char	*strsub;
	
	if (!(strsub = ft_substr(str, 7, 10)))
			write(1, "NULL", 4);
		else
			printf("%s", strsub);
		if (str == strsub)
			printf("\nA new string was not returned");
}*/
