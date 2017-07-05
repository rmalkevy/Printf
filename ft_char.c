/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:44:08 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/02/03 16:44:50 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_zero_char(char *format)
{
	int i;
	int zero;

	i = 0;
	zero = 0;
	while (format[i])
	{
		if (format[i] == '0' && !(format[i - 1] >= '1' && format[i - 1] <= '9'))
			zero = 1;
		i++;
	}
	return (zero);
}

void	ft_print_char(char *format, char c)
{
	int width;

	width = 0;
	if (ft_width(format) > 1)
		width = ft_width(format) - 1;
	if (ft_minus(format))
		ft_putchar(c);
	while (width)
	{
		if (ft_zero_char(format) && !ft_minus(format))
			ft_putchar('0');
		else
			ft_putchar(' ');
		width--;
	}
	if (!ft_minus(format))
		ft_putchar(c);
}

void	ft_char(char *format, va_list ap)
{
	char c;

	c = va_arg(ap, int);
	ft_print_char(format, c);
}
