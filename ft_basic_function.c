/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khebert <khebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 22:48:15 by khebert           #+#    #+#             */
/*   Updated: 2025/11/23 00:02:37 by khebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* For %c and %% */

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

/* For %s */

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

/* For %u */

int	ft_putunsigned(unsigned long int n)
{
	unsigned int	counter;

	counter = 0;
	if (n >= 0 && n <= 9)
	{
		n += '0';
		write(1, &n, 1);
		counter++;
	}
	else
	{
		counter += ft_putunsigned(n / 10);
		counter += ft_putunsigned(n % 10);
	}
	return (counter);
}

/* For %d %i */

int	ft_putnbr(int c, int counter)
{
	counter = 0;
	if (c == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (c < 0)
	{
		write(1, "-", 1);
		c *= -1;
		counter++;
	}
	if (c >= 0 && c <= 9)
	{
		c += '0';
		write(1, &c, 1);
		counter++;
	}
	else
	{
		counter += ft_putnbr(c / 10, counter);
		counter += ft_putnbr(c % 10, counter);
	}
	return (counter);
}
