/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num_with_minus_16.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:43:03 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/02/08 19:14:02 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_zero_prec(char *format, uintmax_t num, t_struct *mod)
{
	if (ft_precision(format) == -1 && num == 0)
		return (1);
	else if (ft_precision(format) == 0 && num == 0 && mod->sharp
			&& mod->conversion == 'O')
		return (1);
	else if (ft_precision(format) == 0 && num == 0 && mod->sharp
			&& mod->conversion == 'o')
		return (1);
	return (0);
}

void	print_minus_16(char *format, uintmax_t num, int base, t_struct *mod)
{
	if (mod->sharp)
		ft_putstr(mod->sharp);
	if (mod->precision > 0)
		ft_print_symbol(mod->precision, '0');
	if (!ft_zero_prec(format, num, mod))
		ft_itoa_base_unsigned(format, num, base);
	if (mod->width > 0)
		ft_print_symbol(mod->width, ' ');
}

void	ft_print_num_16(char *format, uintmax_t num, int base)
{
	t_struct *mod;

	mod = ft_create_struct();
	mod = ft_flags(format, num, base, mod);
	if (mod->minus)
		print_minus_16(format, num, base, mod);
	else if (!mod->minus)
	{
		if (mod->sharp && mod->zero)
			ft_putstr(mod->sharp);
		ft_print_width(mod);
		if (mod->sharp && !mod->zero)
			ft_putstr(mod->sharp);
		if (mod->precision > 0)
			ft_print_symbol(mod->precision, '0');
		if (!ft_zero_prec(format, num, mod))
			ft_itoa_base_unsigned(format, num, base);
	}
	if (mod->sharp)
	{
		free(mod->sharp);
		mod->sharp = NULL;
	}
	free(mod);
}

void	ft_16(char *format, va_list ap)
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
	else if (ft_find_flag(format, 'h') == 2)
		num = (unsigned char)va_arg(ap, unsigned int);
	else if (ft_find_flag(format, 'h') == 1)
		num = (unsigned short int)va_arg(ap, unsigned int);
	else
		num = va_arg(ap, unsigned int);
	ft_print_num_16(format, num, 16);
}

void	ft_pointer(char *format, va_list ap)
{
	uintmax_t num;

	num = va_arg(ap, unsigned long);
	ft_print_num_16(format, num, 16);
}
