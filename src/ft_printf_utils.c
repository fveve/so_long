/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:38:44 by arafa             #+#    #+#             */
/*   Updated: 2024/02/12 10:31:28 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_strlen(const char	*s)
{
	int	x;

	x = 0;
	while (s[x])
	{
		x++;
	}
	return (x);
}

void	ft_putchar_fd(char c, int fd, int *count)
{
	*count += 1;
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd, int *count)
{
	int	x;

	if (fd > 0)
	{
		x = 0;
		while (s[x])
		{
			*count += 1;
			write(fd, &s[x], 1);
			x++;
		}
	}
}

void	ft_putnbr_base_fd(int n, int fd, char *base, int *count)
{
	int	mod;
	int	a;

	a = ft_strlen(base);
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", 1, count);
	else
	{
		if (n < 0)
		{
			mod = -n;
			n = -n;
			ft_putchar_fd('-', fd, count);
		}
		else
			mod = n;
		if (n > a - 1)
		{
			mod = n % a;
			ft_putnbr_base_fd(n / a, fd, base, count);
		}
		ft_putchar_fd(base[mod], fd, count);
	}
}

void	ft_putnbr(unsigned long long n, char *base, int *count)
{
	unsigned long long	mod;
	unsigned long long	a;

	a = ft_strlen(base);
	mod = n;
	if (n > a - 1)
	{
		mod = n % a;
		ft_putnbr(n / a, base, count);
	}
	ft_putchar_fd(base[mod], 1, count);
}
