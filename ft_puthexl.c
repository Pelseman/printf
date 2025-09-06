/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelseman <pelseman@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:57:18 by pelseman          #+#    #+#             */
/*   Updated: 2025/06/23 11:57:20 by pelseman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexl(unsigned int n)
{
	char	*hex;
	char	digits[8];
	int		len;	
	int		i;

	len = 0;
	i = 0;
	hex = "0123456789abcdef";
	if (n == 0)
	{
		return (ft_putchar('0'));
	}
	while (n > 0)
	{
		digits[i++] = (hex[n % 16]);
		n = n / 16;
	}
	while (i--)
	{
		len += ft_putchar(digits[i]);
	}
	return (len);
}
