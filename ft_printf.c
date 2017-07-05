/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:47:14 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/02/03 15:55:58 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_function(char *format, va_list ap)
{
	char a;

	a = (char)ft_conversion(format);
	if (a == 'd' || a == 'i' || a == 'D')
		ft_10(format, ap);
	else if (a == 's' && !ft_find_flag(format, 'l'))
		ft_string(format, ap);
	else if (a == 'S' || (a == 's' && ft_find_flag(format, 'l')))
		ft_wstring(format, ap);
	else if (a == 'c' || a == 'C')
		ft_char(format, ap);
	else if (a == 'x' || a == 'X')
		ft_16(format, ap);
	else if (a == 'o' || a == 'O')
		ft_8(format, ap);
	else if (a == 'u' || a == 'U')
		ft_u10(format, ap);
	else if (a == 'p')
		ft_pointer(format, ap);
	else if (a == 'b')
		ft_u2(format, ap);
	else if (a == 'n')
		ft_number_printed_symbols(ap);
	else
		return ;
}

int		ft_printf(char *format, ...)
{
	va_list		ap;
	int			i;

	i = -1;
	g_star = 0;
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				break ;
			if (g_minus != 0)
				g_minus = 0;
			i = ft_distributor(format, i + 1, ap);
			if (format[i] == '\0')
				break ;
		}
		else
			ft_putchar(format[i]);
	}
	va_end(ap);
	return (g_star);
}
