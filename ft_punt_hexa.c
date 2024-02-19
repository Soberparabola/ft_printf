/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_punt_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordgarc <jordgarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:38:11 by jordgarc          #+#    #+#             */
/*   Updated: 2024/02/19 18:58:15 by jordgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexa_pointer(char *bstr, unsigned long long n, int c)
{
	unsigned long long	b;

	b = ft_strlen(bstr);
	if (n >= b)
	{
		c = hexa_pointer(bstr, n / b, c);
		if (c == -1)
			return (-1);
		if (write (1, &bstr[n % b], 1) == -1)
			return (-1);
		c++;
	}
	else if (n < b)
	{
		if (write (1, &bstr[n], 1) == -1)
			return (-1);
		c++;
	}
	return (c);
}

int	ft_punt_hexa(void *p)
{
	unsigned long long	pointer;
	int					temp;

	temp = 0;
	pointer = (unsigned long long)p;
	if (write(1, "0x", 2) != 2)
		return (-1);
	temp = hexa_pointer("0123456789abcdef", pointer, temp);
	if (temp == -1)
		return (-1);
	temp += 2;
	return (temp);
}
