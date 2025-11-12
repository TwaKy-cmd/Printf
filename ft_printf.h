/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khebert <khebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 23:12:41 by khebert           #+#    #+#             */
/*   Updated: 2025/11/12 02:11:27 by khebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *, ...);
int ft_putstr(char *str);
int	ft_putunsigned(unsigned int n);
int	ft_putnbr(int c, int counter);
int	hexa_lower(int c);
int	hexa_upper(int c);
int	print_ptr(void *ptr);

#endif