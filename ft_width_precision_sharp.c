/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_precision_sharp.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:33:01 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/02/03 16:42:16 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_sharp(char *format, uintmax_t num, t_struct *mod)
{
	int i;

	i = -1;
	mod->sharp = NULL;
	while (format[++i])
	{
		if (format[i] == '#')
		{
			if (mod->conversion == 'X' && num != 0)
				mod->sharp = ft_strdup("0X");
			else if (mod->conversion == 'x' && num != 0)
				mod->sharp = ft_strdup("0x");
			break ;
		}
	}
	if (mod->conversion == 'p')
		mod->sharp = ft_strdup("0x");
	return (mod->sharp);
}

int		ft_width(char *format)
{
	int i;
	int width;

	i = 0;
	width = 0;
	while (format[i])
	{
		if (format[i] > '0' && format[i] <= '9'
			&& (format[i - 1] < '1' || format[i - 1] > '9')
			&& format[i - 1] != '.')
		{
			width = ft_atoi(format + i);
		}
		i++;
	}
	return (width);
}

int		ft_precision(char *format)
{
	int end;
	int precision;

	end = (int)ft_strlen(format);
	while (end > -1)
	{
		if (format[end] == '.')
		{
			precision = ft_atoi(format + end + 1);
			if (precision == 0 || format[end + 1] < '0'
				|| format[end + 1] > '9')
				return (-1);
			return (precision);
		}
		end--;
	}
	return (0);
}

void	ft_print_symbol(int count, int symbol)
{
	if (count > 0)
		while (count)
		{
			ft_putchar((char)symbol);
			count--;
		}
}

void	ft_print_width(t_struct *mod)
{
	if (mod->width > 0)
	{
		if (mod->zero && !mod->minus)
			ft_print_symbol(mod->width, '0');
		else
			ft_print_symbol(mod->width, ' ');
	}
}
