/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khebert <khebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 23:11:33 by khebert           #+#    #+#             */
/*   Updated: 2025/11/28 18:51:04 by khebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	for_string(va_list args)
{
	int		counter;
	char	*s;

	counter = 0;
	s = va_arg(args, char *);
	if (!s)
	{
		write(1, "(null)", 6);
		counter += 6;
	}
	else
		counter += ft_putstr(s);
	return (counter);
}

int	printf_format(const char *str, va_list args)
{
	int	counter;

	counter = 0;
	if (str[0] == 'c')
		counter += ft_putchar(va_arg(args, int));
	else if (str[0] == 's')
		counter += for_string(args);
	else if (str[0] == 'p')
		counter += print_ptr(va_arg(args, void *));
	else if (str[0] == 'd')
		counter += ft_putnbr(va_arg(args, int), 0);
	else if (str[0] == 'i')
		counter += ft_putnbr(va_arg(args, int), 0);
	else if (str[0] == 'u')
		counter += ft_putunsigned(va_arg(args, unsigned int));
	else if (str[0] == 'x')
		counter += hexa_lower(va_arg(args, unsigned int));
	else if (str[0] == 'X')
		counter += hexa_upper(va_arg(args, unsigned int));
	else if (str[0] == '%')
		counter += ft_putchar('%');
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		counter;
	int		i;

	i = 0;
	counter = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
			counter += printf_format(&str[++i], args);
		else
			counter += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (counter);
}
int main(void)
{
    int n = 42;
    char c = 'F';
    char *s = "hello";
    unsigned int u = 598985484u;
    int counter;
    counter = ft_printf("Test Integrale : \n C : %c\n S : %s\n P : %p\n D : %d\n I : %i\n U : %u\n x : %x\n X : %X\n %% : %%\n", c, s, &n, n, n, u, n, n);
    ft_printf("\nTotal ecris par printf : %u\n", counter);
	int counter2;
    counter2 = printf("Test Integrale : \n C : %c\n S : %s\n P : %p\n D : %d\n I : %i\n U : %u\n x : %x\n X : %X\n %% : %%\n", c, s, &n, n, n, u, n, n);
    printf("\nTotal ecris par printf : %u\n", counter2);
	ft_printf("%x\n", 16);
	printf("%x\n", 16);
}