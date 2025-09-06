/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelseman <pelseman@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:51:08 by pelseman          #+#    #+#             */
/*   Updated: 2025/06/23 11:50:26 by pelseman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_type(const char *str, va_list args)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (str[i] == 'c')
		len += ft_putchar(va_arg(args, int));
	if (str[i] == 's')
		len += ft_putstr(va_arg(args, char *));
	if (str[i] == 'p')
		len += ft_putptr(va_arg(args, void *));
	if (str[i] == 'd' || str[i] == 'i')
		len += ft_putnbr(va_arg(args, int));
	if (str[i] == 'u')
		len += ft_putunbr(va_arg(args, unsigned int));
	if (str[i] == 'x')
		len += ft_puthexl(va_arg(args, unsigned int));
	if (str[i] == 'X')
		len += ft_puthexu(va_arg(args, unsigned int));
	if (str[i] == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	size_t	len;
	size_t	i;
	va_list	args;

	i = 0;
	len = 0;
	va_start (args, str);
	while (*str)
	{
		if (*str == '%')
		{
			len += ft_type(++str, args);
			str++;
		}
		else
		{
			len += write(1, &str[i], 1);
			str++;
		}
	}
	va_end(args);
	return (len);
}
/*
int	main (int argc, char **argv)
{
	if (argc)
	{
		ft_printf("%c, %s, %d, %u, %x, %X, %p",
		argv[1][0], argv[2], atoi(argv[3]), atoi(argv[4])
		,atoi(argv[5]), atoi(argv[6]), argv[7]);
		write(1, "\n", 1);
		printf("%c, %s, %d, %u, %x, %X, %p",
		argv[1][0], argv[2], atoi(argv[3]), atoi(argv[4])
		, atoi(argv[5]), atoi(argv[6]), argv[7]);
	}
	else
	{
		write(1, "x", 1);
		write(1, "\n", 1);
	}
}*/
