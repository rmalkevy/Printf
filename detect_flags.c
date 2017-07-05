/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:56:39 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/02/03 15:57:47 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	*ft_create_struct(void)
{
	t_struct *mod;

	mod = (t_struct*)malloc(sizeof(t_struct));
	return (mod);
}

t_struct	*ft_flags(char *format, uintmax_t num, int base, t_struct *mod)
{
	int			sc_pls;
	int			len_sharp;
	int			len_number;

	sc_pls = 0;
	len_number = ft_len_num(num, base);
	mod->plus_space = ft_plus_space(format);
	if (mod->plus_space && g_minus == 0)
		sc_pls++;
	mod->precision = ft_precision(format) - len_number;
	if (mod->precision < 0)
		mod->precision = 0;
	mod->conversion = ft_conversion(format);
	mod->minus = ft_minus(format);
	mod->len_num = len_number - ft_zero_prec(format, num, mod) + g_minus;
	mod->zero = ft_zero(format);
	mod->sharp = ft_sharp(format, num, mod);
	len_sharp = (int)ft_strlen(mod->sharp);
	mod->width = ft_width(format) - sc_pls;
	mod->width = mod->width - mod->precision - mod->len_num - len_sharp;
	return (mod);
}

int			ft_find_flag(char *format, int c)
{
	int i;
	int flag;

	i = -1;
	flag = 0;
	while (format[++i])
	{
		if (format[i] == c)
			flag++;
	}
	if (flag && flag % 2 == 0)
		return (2);
	if (flag && flag % 2 == 1)
		return (1);
	return (0);
}
