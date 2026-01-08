/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:01:49 by jsantini          #+#    #+#             */
/*   Updated: 2025/11/14 10:12:52 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putstr(const char *s, int *count)
{
	if (s == NULL)
		return ;
	while (*s)
	{
		write(1, s, 1);
		s++;
		(*count)++;
	}
}

void	printf_string(const char *string, int *count)
{
	if (string == NULL)
		putstr("(null)", count);
	else
		putstr(string, count);
}

void	ft_putnbr(int n, int *count)
{
	char	aff;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*count += 11;
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		*count += 1;
		n *= -1;
	}
	if (n > 9)
		ft_putnbr(n / 10, count);
	aff = (n % 10) + '0';
	(*count)++;
	write(1, &aff, 1);
}

const char	*execption(va_list param, const char *str, int *count)
{
	uintptr_t	test;

	if (*(str + 1) == 's')
		printf_string((const char *)va_arg(param, const char *), count);
	if (*(str + 1) == '%')
		ft_putchar('%', count);
	if (*(str + 1) == 'c')
		ft_putchar((int)va_arg(param, int), count);
	if (*(str + 1) == 'i' || *(str + 1) == 'd')
		ft_putnbr((int)va_arg(param, int), count);
	if (*(str + 1) == 'p')
	{
		test = (uintptr_t)va_arg(param, void *);
		if (test == 0)
			putstr("(nil)", count);
		else
		{
			*count += write(1, "0x", 2);
			ft_putnbr_base(test, "0123456789abcdef", count);
		}
	}
	rest(param, str, count);
	return (str + 2);
}

int	ft_printf(const char *str, ...)
{
	va_list	param;
	int		count[1];

	va_start(param, str);
	*count = 0;
	if (!str)
		return (-1);
	while (*str)
	{
		while (*str != '%' && *str)
		{
			write(1, str, 1);
			str++;
			(*count)++;
		}
		if (*str == '%')
			str = execption(param, str, count);
	}
	va_end(param);
	return (*count);
}
/*
int	main(int argc, char **argv)
{
	char	*temp;

	ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% 
	%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', 
	"-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	ft_printf(" %p %p ", 0, 0);
	printf("\n%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% 
	%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', 
	"-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	ft_printf("%d : ", printf("tata""toto\n"));
	ft_printf("%d : ", ft_printf("tata""toto\n"));
	ft_printf("ft_11 %u \n", 100);
	ft_printf("ft_12 %u \n", 101);
	ft_printf("5 %u \n", 10);
	printf("5 %u \n", 10);
	printf("11 %u \n", 100);
	printf("12 %u ", 101);
	ft_printf("| %d | ", ft_printf("\n%s", NULL));
	printf("| %d | ", printf("\n%s", NULL));
}*/
