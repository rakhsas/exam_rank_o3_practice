/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:24:49 by rakhsas           #+#    #+#             */
/*   Updated: 2023/02/13 18:40:44 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "stdio.h"
int ft_len(int n)
{
	int     len;

	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}
char    *ft_itoa(int n)
{
	int     i;
	char    *num;
	int     len;

	i = 0;
	len = ft_len(n);
	num = malloc(sizeof(char) * len + 1);
	if (!num)
		return (0);
	num[len] = '\0';
	while (n)
	{
		num[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (num);
}
int print_str(char *str)
{
	int i;

	i = 0;
	while (i[str])
	{
		write(1, &i[str], 1);
		i++;
	}
	return (i);
}

int print_char(int c)
{
	write(1, &c, 1);
	return (1);
}
int	ft_printhexa(unsigned int c)
{
	int i;
	char hexa[16] = "0123456789abcdef";
	
	if (c >= 16)
		ft_printhexa(c / 16);
	c %= 16;
	write(1, &hexa[c % 16], 1);
	i++;
	return (i);
}
int funct1(char c, va_list lst)
{
	int i;

	i = 0;
	if (!c)
		return (0);
	if (c == 'd')
		i = print_str(ft_itoa(va_arg(lst, int)));
	else if (c == 's')
		i = print_str(va_arg(lst, char *));
	else if (c == 'x')
		i = ft_printhexa(va_arg(lst, unsigned int));
	else
		i = print_char(va_arg(lst, int));
	return (i);
}

int ft_printf(const char *format, ... )
{
	va_list	lst;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(lst, format);
	while (i[format])
	{
		if (format[i] == '%')
		{
			len += funct1(format[i + 1], lst);
			i++;
		}
		else
			len += print_char(format[i]);
		i++;
	}
	va_end(lst);
	return (len);
}

int main()
{
	ft_printf("%d", ft_printf("%s\t", "25"));
	// ft_printf("%s\n", "HELLO WORLD!!");
}
