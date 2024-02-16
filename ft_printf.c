/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordgarc <jordgarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:37:40 by jordgarc          #+#    #+#             */
/*   Updated: 2024/02/16 18:29:39 by jordgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	val_type(char c, va_list element);

//Coge el valor despues del %, si es solo el % lo imprime por salida
static int	char_percent(char c, va_list element)
{
	int	let;

	let = 0;
	if (c != '%')
	{
		let = val_type(c, element);
		if (let == -1)
			return (-1);
		return (let);
	}
	else
	{
		if (write (1, &c, 1) != 1)
			return (-1);
		return (1);
	}
}

//Comprueba si hay un %, si no lo hay, imprime los caracteres en la salida
static	int	char_admin(const char *str, va_list element, int let)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			let = let + char_percent(str[i + 1], element);
			if (let == -1)
				return (-1);
			i++;
		}
		else
		{
			if (write (1, &str[i], 1) != 1)
				return (-1);
			let++;
		}
		i++;
	}
	return (let);
}

int	ft_printf(const char *str, ...)
{
	va_list	element;
	int		let;

	let = 0;
	va_start(element, str);
	let = char_admin(str, element, let);
	va_end(element);
	return (let);
}

static int	val_type(char c, va_list element)
{
	if (c == 'c')
		return (ft_putchar(va_arg(element, int)));
	if (c == 's')
		return (ft_putstr(va_arg(element, char *)));
	if (c == 'p')
		return (ft_punt_hexa(va_arg(element, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(element, int)));
	if (c == 'u')
		return (ft_num_nosign(va_arg(element, unsigned int)));
	if (c == 'x')
		return (ft_hexa_min(va_arg(element, int)));
	if (c == 'X')
		return (ft_hexa_mayus(va_arg(element, int)));
	return (0);
}
