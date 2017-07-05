/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:37:25 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/02/03 16:46:37 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conversion(char *format)
{
	char	*flags;
	int		j;
	int		i;

	i = 0;
	flags = "sSpdDioOuUxXcCeEfFgGaAnbrk";
	while (format[i])
	{
		j = 0;
		while (format[i] != flags[j] && flags[j])
			j++;
		if (format[i] == flags[j])
			return (flags[j]);
		i++;
	}
	return (0);
}

int		ft_plus_space(char *format)
{
	int i;
	int conversion;

	i = -1;
	conversion = ft_conversion(format);
	if (conversion == 'd' || conversion == 'i')
	{
		while (format[++i])
			if (format[i] == '+')
				return ('+');
		i = -1;
		while (format[++i])
			if (format[i] == ' ')
				return (' ');
	}
	return (0);
}

int		ft_minus(char *format)
{
	int i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '-')
			return ('-');
		i++;
	}
	return (0);
}

int		ft_zero(char *format)
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
	if (ft_precision(format))
		zero = 0;
	return (zero);
}

char	*ft_lower_case(char *number)
{
	int i;

	i = 0;
	while (number[i])
	{
		number[i] = (char)ft_tolower(number[i]);
		i++;
	}
	return (number);
}
