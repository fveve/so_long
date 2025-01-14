/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:35:07 by arafa             #+#    #+#             */
/*   Updated: 2024/02/12 10:31:32 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_putnbr_base3(unsigned int n, char *base, int *count)
{
	unsigned int	mod;
	unsigned int	a;

	a = ft_strlen(base);
	mod = n;
	if (n > a - 1)
	{
		mod = n % a;
		ft_putnbr(n / a, base, count);
	}
	ft_putchar_fd(base[mod], 1, count);
}

int	isnull(char x, int *count, va_list arg)
{
	va_list	arg2;

	va_copy(arg2, arg);
	if (x == 's')
	{
		if (!va_arg(arg2, char *))
		{
			write(1, "(null)", 6);
			*count += 6;
			va_end(arg2);
			return (1);
		}
	}
	else if (x == 'p')
	{
		if (!va_arg(arg2, long int))
		{
			write(1, "(nil)", 5);
			*count += 5;
			va_end(arg2);
			return (1);
		}
	}
	va_end(arg2);
	return (0);
}
