/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:45:46 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/02/03 16:04:59 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_precision_string(char *format, char *string)
{
	int end;
	int precision;

	end = (int)ft_strlen(format);
	while (end > -1)
	{
		if (format[end] == '.')
		{
			precision = ft_atoi(format + end + 1);
			return (ft_strsub(string, 0, (size_t)precision));
		}
		end--;
	}
	return (string);
}

int		ft_zero_string(char *format)
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

void	ft_print_string(char *format, char *string)
{
	int width;

	width = 0;
	string = ft_precision_string(format, string);
	if (ft_width(format) > (int)ft_strlen(string))
		width = ft_width(format) - (int)ft_strlen(string);
	if (ft_minus(format))
		ft_putstr(string);
	if (width > 0)
		while (width)
		{
			if (ft_zero_string(format) && !ft_minus(format))
				ft_putchar('0');
			else
				ft_putchar(' ');
			width--;
		}
	if (!ft_minus(format))
		ft_putstr(string);
}

void	ft_string(char *format, va_list ap)
{
	char *string;

	string = va_arg(ap, char*);
	if (!string)
		string = "(null)";
	ft_print_string(format, string);
}
