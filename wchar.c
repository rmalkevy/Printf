/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:42:24 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/02/03 16:05:56 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define BIT7 127
#define BIT11 2047
#define BIT16 65535
#define BIT21 2097151
#define BIT26 67108863
#define BIT31 2147483647

void	ft_addition(const uint32_t symbol, char *wc)
{
	if (symbol <= BIT21)
	{
		wc[0] = ((symbol & 1835008) >> 18) | 240;
		wc[1] = ((symbol & 258048) >> 12) | 128;
		wc[2] = ((symbol & 4032) >> 6) | 128;
		wc[3] = (symbol & 63) | 128;
	}
	else if (symbol <= BIT26)
	{
		wc[0] = ((symbol & 50331648) >> 24) | 248;
		wc[1] = ((symbol & 16515072) >> 18) | 128;
		wc[2] = ((symbol & 258048) >> 12) | 128;
		wc[3] = ((symbol & 4032) >> 6) | 128;
		wc[4] = (symbol & 63) | 128;
	}
	else if (symbol <= BIT31)
	{
		wc[0] = ((symbol & 1073741824) >> 30) | 252;
		wc[1] = ((symbol & 1056964608) >> 24) | 128;
		wc[2] = ((symbol & 16515072) >> 18) | 128;
		wc[3] = ((symbol & 258048) >> 12) | 128;
		wc[4] = ((symbol & 4032) >> 6) | 128;
		wc[5] = (symbol & 63) | 128;
	}
}

void	ft_putwchar(wchar_t symbol)
{
	char	*wc;
	int		count;

	wc = ft_strnew(6);
	if (symbol <= BIT7)
		wc[0] = symbol;
	else if (symbol <= BIT11)
	{
		wc[0] = ((symbol & 1984) >> 6) | 192;
		wc[1] = (symbol & 63) | 128;
	}
	else if (symbol <= BIT16)
	{
		wc[0] = ((symbol & 61440) >> 12) | 224;
		wc[1] = ((symbol & 4032) >> 6) | 128;
		wc[2] = (symbol & 63) | 128;
	}
	else
		ft_addition(symbol, wc);
	count = write(1, wc, sizeof(char)) + write(1, &wc[1], ft_strlen(&wc[1]));
	g_star += count;
	ft_strdel(&wc);
}

void	ft_print_wchar(char *format, wchar_t c)
{
	int width;

	width = 0;
	if (ft_width(format) > 1)
		width = ft_width(format) - 1;
	if (ft_minus(format))
		ft_putwchar(c);
	while (width)
	{
		if (ft_zero_string(format) && !ft_minus(format))
			ft_putchar('0');
		else
			ft_putchar(' ');
		width--;
	}
	if (!ft_minus(format))
		ft_putwchar(c);
}

void	ft_wchar(char *format, va_list ap)
{
	wchar_t c;

	c = va_arg(ap, wchar_t);
	ft_print_wchar(format, c);
}
