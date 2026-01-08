/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:29:32 by jsantini          #+#    #+#             */
/*   Updated: 2025/11/10 15:46:16 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>

int		ft_printf(const char *str, ...);
void	ft_putchar(int c, int *count);
void	ft_putnbr_base(unsigned long nb, char *base, int *count);
void	ft_putnbr_unsigned(unsigned int nb, int *count);
void	rest(va_list param, const char *str, int *count);
#endif
