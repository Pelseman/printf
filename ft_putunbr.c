/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelseman <pelseman@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:52:58 by pelseman          #+#    #+#             */
/*   Updated: 2025/06/23 12:53:00 by pelseman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	size_t	len;
	size_t	i;
	char	digits[10];	

	i = 0;
	len = 0;
	if (n == 0)
	{
		len += ft_putchar('0');
		return (len);
	}
	while (n > 0)
	{
		digits[i++] = (n % 10) + '0';
		n = n / 10;
	}
	while (i--)
		len += ft_putchar(digits[i]);
	return (len);
}
