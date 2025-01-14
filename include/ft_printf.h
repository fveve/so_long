/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:31:30 by arafa             #+#    #+#             */
/*   Updated: 2023/10/17 19:32:01 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

//FUNCTIONS---------------------------------------------------------------------
void	ft_putnbr_base_fd(int n, int fd, char *base, int *count);
void	ft_putnbr(unsigned long long n, char *base, int *count);
void	ft_putnbr_base3(unsigned int n, char *base, int *count);
void	ft_putchar_fd(char c, int fd, int *count);
void	ft_putstr_fd(char *s, int fd, int *count);
int		isnull(char x, int *count, va_list arg);
int		ft_printf(const char *format, ...);
int		ft_strlen(const char	*s);

#endif
