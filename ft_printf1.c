/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:13:50 by rakhsas           #+#    #+#             */
/*   Updated: 2023/02/13 19:43:31 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdarg.h"

int count_len(int c)
{
    int i;

    i = 0;
    if (!c)
        return (i);
    while (c)
    {
        c /= 10;
        i++;
    }
    return (i);
}
char    *ft_itoa(int c)
{
    int     i;
    char    *str;
    int     len;

    i = 0;
    len = count_len(c);
    str = malloc(len + 1);
    if (!str)
        return (NULL);
    printf("%d\n", len);
    str[len] = '\0';
    while (c)
    {
        str[len - 1] = c % 10 + '0';
        c /= 10;
        len--;
    }
    return (str);
}

int print_str(char *c)
{
    int i;

    i = 0;
    while (i[c])
    {
        write(1, &i[c], 1);
        i++;
    }
    return (i);
}

int print_char(char c)
{
    write(1, &c, 1);
    return (1);
}

int next_printf(char c, va_list lst)
{
    int i;

    i = 0;
    if (c == 'd')
        i += print_str(ft_itoa(va_arg(lst, int)));
    return (i);
}

int ft_printf(const char *c, ...)
{
    va_list lst;
    int     len;
    int     i;

    i = 0;
    len = 0;
    va_start(lst, c);
    while (i[c])
    {
        if (i[c] == '%')
        {
            len += next_printf(c[i + 1], lst);
            i++;
        }
        else
            len += print_char(c[i]);
        i++;
    }
    va_end(lst);
    return (len);
}
int main()
{
    ft_printf("%d", ft_printf("hello world"));
}