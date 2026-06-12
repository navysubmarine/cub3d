/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemouge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:28:53 by bdemouge          #+#    #+#             */
/*   Updated: 2025/12/03 15:31:27 by bdemouge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	pf_putchar(char c);
int	pf_putstr(char *s);
int	pf_putnbr(int n);
int	pf_putunsigned(unsigned int nb);
int	pf_puthexa_lower(unsigned long long nb);
int	pf_puthexa_upper(unsigned long long nb);
int	pf_putad(unsigned long long ad);

#endif
