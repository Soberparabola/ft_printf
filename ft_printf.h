/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordgarc <jordgarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:19:10 by jordgarc          #+#    #+#             */
/*   Updated: 2024/02/12 18:50:04 by jordgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int				ft_putchar(int c);
int				ft_putnbr(int n);
int				ft_putstr(char *s);
int				ft_printf(const	char *str, ...);
unsigned int	ft_num_nosign(unsigned int num);
int				ft_punt_hexa(void *p);
int				ft_hexa_min(int num);
int				ft_hexa_mayus(int num);
int				ft_strlen(char *s);

#endif
