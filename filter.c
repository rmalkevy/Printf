/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:39:17 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/02/03 16:13:41 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_zero_undef(char *format)
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

void	ft_undefined(char *format, int c)
{
	int width;

	width = ft_width(format);
	if (width >= 1)
		width -= 1;
	if (!ft_minus(format) && ft_zero_undef(format))
	{
		ft_print_symbol(width, '0');
		ft_putchar((char)c);
	}
	else if (ft_minus(format))
	{
		ft_putchar((char)c);
		ft_print_symbol(width, ' ');
	}
	else
	{
		ft_print_symbol(width, ' ');
		ft_putchar((char)c);
	}
}

int		ft_end_format(char *format, int i)
{
	char	*undefined;
	int		j;
	int		flag;

	undefined = "hlzj +-#0123456789*.";
	while (format[i])
	{
		j = 0;
		flag = 0;
		while (undefined[j])
		{
			if (format[i] == undefined[j])
				flag++;
			j++;
		}
		if (flag == 0)
			return (i);
		i++;
	}
	return (i);
}

int		ft_filter(char *format, int end)
{
	char	*flags;
	int		j;

	flags = "sSpdDioOuUxXcCeEfFgGaAnb";
	j = 0;
	while (flags[j])
	{
		if (format[end] == flags[j])
			return (end);
		j++;
	}
	return (0);
}

int		ft_distributor(char *format, int i, va_list ap)
{
	char	*freesh;
	int		end;

	end = ft_end_format(format, i);
	if (format[end] != '\0')
	{
		freesh = ft_strsub(format, (unsigned)i, (size_t)end + 1 - i);
		if (ft_filter(format, end))
			ft_function(freesh, ap);
		else
			ft_undefined(freesh, format[end]);
		if (freesh)
			free(freesh);
	}
	return (end);
}
