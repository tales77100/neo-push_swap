/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:36:27 by jsantini          #+#    #+#             */
/*   Updated: 2025/11/14 09:44:39 by jsantini         ###   ########.fr       */
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

static int	is_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static int	start_set(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] && is_set(s1[i], set))
		i++;
	return (i);
}

static int	last_set(char const *s1, char const *set)
{
	int	i;
	int	count;

	i = len((char *)s1);
	count = 0;
	while (i > 0 && is_set(s1[i - 1], set))
	{
		i--;
		count++;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*final;
	int		i;
	int		last;
	int		start;
	int		len_s;

	start = start_set(s1, set);
	last = last_set(s1, set);
	len_s = len((char *)s1);
	if (len_s == start)
		final = malloc(sizeof(char) * 1);
	else
		final = malloc(sizeof(char) * (len_s - (start + last) + 1));
	if (!final)
		return (final);
	i = 0;
	s1 += start;
	while (*s1 && len_s - (i + start) != last)
		final[i++] = *(s1++);
	final[i] = '\0';
	return (final);
}
/*
int	main(void)
{
	char	test[] = ", ,salut, les gen! ,";
	char	*temp;

	temp = ft_strtrim("   xxx   xxx", " x");
	printf("%s\n", temp);
	temp = ft_strtrim(test, ",");
        printf("%s\n", temp);
	temp = ft_strtrim("", " ");
        printf("%s\n", temp);

}*/
