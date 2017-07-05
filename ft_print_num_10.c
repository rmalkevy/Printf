/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num_with_minus_10.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:42:24 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/02/03 16:05:56 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_minus_10(char *format, uintmax_t num, t_struct *mod)
{
	if (g_minus > 0)
		ft_putchar('-');
	if (g_minus == 0 && mod->plus_space)
		ft_putchar((char)mod->plus_space);
	if (mod->precision > 0)
		ft_print_symbol(mod->precision, '0');
	if (!ft_zero_prec(format, num, mod))
		ft_putnbr(num);
	if (mod->width > 0)
		ft_print_symbol(mod->width, ' ');
}

void	print_10(char *format, uintmax_t num, t_struct *mod)
{
	if (mod->zero && g_minus == 0 && mod->plus_space)
		ft_putchar((char)mod->plus_space);
	if (g_minus > 0 && mod->zero)
		ft_putchar('-');
	ft_print_width(mod);
	if (g_minus > 0 && !mod->zero)
		ft_putchar('-');
	if (g_minus == 0 && mod->plus_space && !mod->zero)
		ft_putchar((char)mod->plus_space);
	if (mod->precision > 0)
		ft_print_symbol(mod->precision, '0');
	if (!ft_zero_prec(format, num, mod))
		ft_putnbr(num);
}

void	ft_print_num_10(char *format, uintmax_t num, int base)
{
	t_struct *mod;

	mod = ft_create_struct();
	mod = ft_flags(format, num, base, mod);
	if (mod->minus)
		print_minus_10(format, num, mod);
	else if (!mod->minus)
		print_10(format, num, mod);
	free(mod);
}

void	ft_10(char *format, va_list ap)
{
	intmax_t num;

	if (ft_find_flag(format, 'D'))
		num = va_arg(ap, long);
	else if (ft_find_flag(format, 'j'))
		num = va_arg(ap, intmax_t);
	else if (ft_find_flag(format, 'l') == 2)
		num = va_arg(ap, long long);
	else if (ft_find_flag(format, 'l') == 1)
		num = va_arg(ap, long);
	else if (ft_find_flag(format, 'z'))
		num = va_arg(ap, size_t);
	else if (ft_find_flag(format, 'h') == 1)
		num = (short int)va_arg(ap, int);
	else if (ft_find_flag(format, 'h') == 2)
		num = (signed char)va_arg(ap, int);
	else
		num = va_arg(ap, int);
	if (num < 0)
	{
		num = -num;
		g_minus++;
	}
	ft_print_num_10(format, (uintmax_t)num, 10);
}

void	ft_u10(char *format, va_list ap)
{
	uintmax_t num;

	if (ft_find_flag(format, 'U'))
		num = va_arg(ap, unsigned long);
	else if (ft_find_flag(format, 'j'))
		num = va_arg(ap, uintmax_t);
	else if (ft_find_flag(format, 'l') == 2)
		num = va_arg(ap, unsigned long long);
	else if (ft_find_flag(format, 'l') == 1)
		num = va_arg(ap, unsigned long);
	else if (ft_find_flag(format, 'z'))
		num = va_arg(ap, size_t);
	else if (ft_find_flag(format, 'h') == 1)
		num = (unsigned short int)va_arg(ap, unsigned int);
	else if (ft_find_flag(format, 'h') == 2)
		num = (unsigned char)va_arg(ap, unsigned int);
	else
		num = va_arg(ap, unsigned int);
	ft_print_num_10(format, num, 10);
}
