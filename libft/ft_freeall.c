/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:27:23 by jsantini          #+#    #+#             */
/*   Updated: 2025/12/03 14:28:56 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_freeall(char **temp)
{
	char	**ori;

	ori = temp;
	if (!temp)
		return (NULL);
	while (*temp)
		free(*(temp++));
	free(ori);
	return (NULL);
}
