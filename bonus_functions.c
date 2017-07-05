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

void	ft_number_printed_symbols(va_list ap)
{
	int *p;

	p = va_arg(ap, int*);
	*p = g_star;
}

void	ft_print_num_2(char *format, uintmax_t num, int base)
{
	t_struct *mod;

	mod = ft_create_struct();
	mod = ft_flags(format, num, base, mod);
	if (mod->minus)
	{
		if (mod->precision > 0)
			ft_print_symbol(mod->precision, '0');
		if (!ft_zero_prec(format, num, mod))
			ft_itoa_base_unsigned(format, num, base);
		if (mod->width > 0)
			ft_print_symbol(mod->width, ' ');
	}
	else if (!mod->minus)
	{
		ft_print_width(mod);
		if (mod->precision > 0)
			ft_print_symbol(mod->precision, '0');
		if (!ft_zero_prec(format, num, mod))
			ft_itoa_base_unsigned(format, num, base);
	}
	free(mod);
}

void	ft_u2(char *format, va_list ap)
{
	uintmax_t num;

	if (ft_find_flag(format, 'j'))
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
	ft_print_num_2(format, num, 2);
}
