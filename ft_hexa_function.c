/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khebert <khebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 01:10:13 by khebert           #+#    #+#             */
/*   Updated: 2025/11/12 02:11:34 by khebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	hexa_lower(int c)
{
	int reste;
	int counter;
	
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

int	hexa_upper(int c)
{
	int reste;
	int counter;
	
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
		c = 'A' + (reste - 10);
		write(1, &c, 1);
		counter++;
	}
	return (counter);
}

int	print_ptr(void *ptr)
{
	unsigned long cast_ptr;
	unsigned int counter;
	unsigned int adresse;

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