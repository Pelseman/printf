/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelseman <pelseman@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:03:44 by pelseman          #+#    #+#             */
/*   Updated: 2025/06/23 12:22:30 by pelseman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	writenbr(char digits[11], size_t *len, size_t i)
{
	while (i--)
		*len += ft_putchar(digits[i]);
}

int	ft_putnbr(int n)
{
	size_t	len;
	size_t	i;
	char	digits[10];
	long	nb;

	len = 0;
	i = 0;
	nb = n;
	if (n < 0)
	{
		len += ft_putchar('-');
		nb = -nb;
	}
	if (nb == 0)
	{
		len += ft_putchar('0');
		return (len);
	}
	while (nb > 0)
	{
		digits[i++] = (nb % 10) + '0';
		nb = nb / 10;
	}
	writenbr(digits, &len, i);
	return (len);
}
