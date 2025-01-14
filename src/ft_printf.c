/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:37:56 by arafa             #+#    #+#             */
/*   Updated: 2024/02/20 12:00:30 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	fill(char x, va_list arg, int *count)
{
	if (isnull(x, count, arg) == 1)
		return ;
	else
	{
		if (x == 's')
			ft_putstr_fd(va_arg(arg, char *), 1, count);
		else if (x == 'c')
			ft_putchar_fd(va_arg(arg, int), 1, count);
		else if (x == 'i' || x == 'd')
			ft_putnbr_base_fd(va_arg(arg, int), 1, "0123456789", count);
		else if (x == 'u')
			ft_putnbr_base3(va_arg(arg, int), "0123456789", count);
		else if (x == 'x')
			ft_putnbr(va_arg(arg, unsigned int), "0123456789abcdef", count);
		else if (x == 'X')
			ft_putnbr(va_arg(arg, unsigned int), "0123456789ABCDEF", count);
		else if (x == 'p')
		{
			*count += write (1, "0x", 2);
			ft_putnbr(va_arg(arg, long long), "0123456789abcdef", count);
		}
		else if (x == '%')
			ft_putchar_fd('%', 1, count);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		x;
	int		count;

	x = 0;
	count = 0;
	va_start(arg, format);
	while (format[x])
	{
		if (format[x] == '%')
		{
			++x;
			fill(format[x], arg, &count);
		}
		else
		{
			count ++;
			write(1, &format[x], 1);
		}
		x++;
	}
	va_end(arg);
	return (count);
}
