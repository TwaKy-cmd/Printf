/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khebert <khebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 01:10:13 by khebert           #+#    #+#             */
/*   Updated: 2025/11/22 23:39:36 by khebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* For %x */

int	hexa_lower(unsigned long c)
{
	int	reste;
	int	counter;

	counter = 0;
	if (c >= 16)
		counter += hexa_lower(c / 16);
	reste = (c % 16);
	if (reste < 10)
	{
		c = '0' + reste;
		write(1, &c, 1);
		counter++;
	}
	else
	{
		c = 'a' + (reste - 10);
		write(1, &c, 1);
		counter++;
	}
	return (counter);
}

/* For %X */

int	hexa_upper(unsigned long c)
{
	int	reste;
	int	counter;

	counter = 0;
	if (c >= 16)
		counter += hexa_upper(c / 16);
	reste = (c % 16);
	if (reste < 10)
	{
		c = '0' + reste;
		write(1, &c, 1);
		counter++;
	}
	else
	{
		c = 'A' + (reste - 10);
		write(1, &c, 1);
		counter++;
	}
	return (counter);
}

/* For %p */

int	print_ptr(void *ptr)
{
	unsigned long	cast_ptr;
	unsigned int	counter;

	cast_ptr = (unsigned long) ptr;
	if (!cast_ptr)
	{
		write(1, "(nil)", 5);
		counter = 5;
	}
	if (cast_ptr)
	{
		write(1, "0x", 2);
		counter = hexa_lower(cast_ptr);
		counter += 2;
	}
	return (counter);
}
