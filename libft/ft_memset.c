/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:23:57 by jsantini          #+#    #+#             */
/*   Updated: 2025/11/06 13:52:22 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	temp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		temp[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
	int	*temp2;
	int	*temp3;

	temp2 = malloc(sizeof(char) * 5);
	temp2 = "sale\0";
	temp3 = temp2;
	printf("%p\n", temp2);
	printf("%d\n", temp2[0]);
	temp2 = ft_memset(temp2, 32, 2);
	printf("%p\n", temp3);
	printf("%d", temp3[0]);
}*/
/*
int main()
{
    char buffer[11];
    char buffer2[10];
    ft_memset(buffer, 42, 10);
    memset(buffer2, 42, 10);
    printf("%s\n", buffer);
    buffer[9] = '\0';
    printf("%s\n", buffer2);
    return 0;
}*/
