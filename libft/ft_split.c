/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:28:55 by jsantini          #+#    #+#             */
/*   Updated: 2025/11/10 09:28:59 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_all(char **strs)
{
	char	**ori;

	ori = strs;
	while (*strs != NULL)
	{
		free(*strs);
		strs++;
	}
	free(ori);
	return (NULL);
}

static int	is_char(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int	len_word(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static int	nb_word(char const *s, char c)
{
	int	i;
	int	bol;

	i = 0;
	bol = 0;
	while (*s)
	{
		if (is_char(*s, c) == 0 && bol == 0)
		{
			bol = 1;
			i++;
		}
		if (is_char(*s, c) == 1 && bol == 1)
			bol = 0;
		s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**final;
	int		i;
	int		j;

	final = malloc(sizeof(char *) * (nb_word(s, c) + 1));
	if (!final)
		return (NULL);
	i = 0;
	while (is_char(*s, c) == 1 && *s)
		s++;
	while (*s)
	{
		j = 0;
		final[i] = malloc(sizeof(char) * (len_word(s, c) + 1));
		if (!final[i])
			return (free_all(final));
		while (is_char(*s, c) == 0 && *s)
			final[i][j++] = *(s++);
		final[i++][j] = '\0';
		while (is_char(*s, c) == 1 && *s)
			s++;
	}
	final[i] = NULL;
	return (final);
}
/*
int	main(void)
{
	char **tab;
	char *splitme = malloc(11);
	splitme = "Tripouille";
	tab = ft_split(splitme, ' ');
	while (*tab != NULL)
	{
		printf("%s", *tab);
		tab++;
	}
	return (0);
}*/
