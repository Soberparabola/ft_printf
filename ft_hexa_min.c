/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordgarc <jordgarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:36:40 by jordgarc          #+#    #+#             */
/*   Updated: 2024/02/19 18:31:47 by jordgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	puthexa_pos(char *bstr, unsigned long long n, int c)
{
	unsigned long long	b;

	b = ft_strlen(bstr);
	if (n >= b)
	{
		c = puthexa_pos(bstr, n / b, c);
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

static int	puthexa_neg(char *bstr, unsigned int n, int c)
{
	unsigned int	b;

	b = ft_strlen(bstr);
	if (n >= b)
	{
		c = puthexa_neg(bstr, n / b, c);
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

int	ft_hexa_min(int n)
{
	int		temp;

	temp = 0;
	if (n >= 0)
		temp = puthexa_pos("0123456789abcdef", n, temp);
	else if (n < 0)
		temp = puthexa_neg("0123456789abcdef", n, temp);
	return (temp);
}
