/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:26:58 by jsantini          #+#    #+#             */
/*   Updated: 2025/11/10 09:27:01 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_int(int nb)
{
	int	i;

	i = 0;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static char	*make_neg(int n, int len)
{
	char	*final;

	final = malloc(sizeof(char) * (len + 2));
	if (!final)
		return (NULL);
	final[0] = '-';
	final[len + 1] = '\0';
	while (n != 0)
	{
		final[len--] = -1 * (n % 10) + '0';
		n /= 10;
	}
	return (final);
}

static char	*make_o(void)
{
	char	*final;

	final = malloc(sizeof(char) * 2);
	if (!final)
		return (NULL);
	final[0] = '0';
	final[1] = '\0';
	return (final);
}

char	*ft_itoa(int n)
{
	char	*final;
	int		len;
	int		len_base;

	if (n == 0)
		return (make_o());
	len = len_int(n);
	if (n < 0)
		return (make_neg(n, len));
	final = malloc(sizeof(char) * (len + 1));
	if (!final)
		return (NULL);
	len_base = len;
	while (n != 0)
	{
		len--;
		final[len] = (n % 10) + '0';
		n /= 10;
	}
	final[len_base] = '\0';
	return (final);
}
/*
int	main(int argc, char **argv)
{
	char	*temp = ft_itoa(atoi(argv[1]));
	printf("%s\n", temp);
}*/
