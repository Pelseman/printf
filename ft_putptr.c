/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelseman <pelseman@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:47:05 by pelseman          #+#    #+#             */
/*   Updated: 2025/06/23 12:47:07 by pelseman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void	*ptr)
{
	char			*hex;
	char			digits[16];
	size_t			len;	
	size_t			i;
	unsigned long	n;

	len = 0;
	i = 0;
	hex = "0123456789abcdef";
	n = (unsigned long)ptr;
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	while (n > 0)
	{
		digits[i++] = (hex[n % 16]);
		n = n / 16;
	}
	len += write(1, "0x", 2);
	while (i--)
		len += ft_putchar(digits[i]);
	return (len);
}
