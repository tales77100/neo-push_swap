/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:40:46 by jsantini          #+#    #+#             */
/*   Updated: 2025/11/14 10:13:06 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(int c, int *count)
{
	char	aff;

	aff = c;
	(*count)++;
	write(1, &aff, 1);
}

void	ft_putnbr_base(unsigned long nb, char *base, int *count)
{
	int					len_base;
	unsigned long int	final;

	final = nb;
	len_base = len(base);
	if (final > (unsigned long)len_base - 1)
	{
		ft_putnbr_base(final / len_base, base, count);
	}
	(*count)++;
	write(1, &base[final % len_base], 1);
}

void	ft_putnbr_unsigned(unsigned int nb, int *count)
{
	unsigned long int	final;
	char				aff;

	final = nb;
	if (final > 9)
		ft_putnbr_unsigned(final / 10, count);
	(*count)++;
	aff = (final % 10) + '0';
	write(1, &aff, 1);
}

void	rest(va_list param, const char *str, int *count)
{
	if (*(str + 1) == 'x')
		ft_putnbr_base((unsigned int)va_arg(param, unsigned int),
			"0123456789abcdef", count);
	if (*(str + 1) == 'X')
		ft_putnbr_base((unsigned int)va_arg(param, unsigned int),
			"0123456789ABCDEF", count);
	if (*(str + 1) == 'u')
		ft_putnbr_unsigned((unsigned int)va_arg(param, unsigned int), count);
}
