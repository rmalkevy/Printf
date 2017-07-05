/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:41:17 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/02/03 16:43:48 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_len_num(uintmax_t value, int base)
{
	int count;

	count = 0;
	if (value <= 0)
		count++;
	while (value != 0)
	{
		count++;
		value = value / base;
	}
	return (count);
}

void	ft_itoa_base_unsigned(char *format, uintmax_t value, int base)
{
	char	*itoa;
	char	*box;
	int		len;

	box = "0123456789ABCDEF";
	len = ft_len_num(value, base);
	itoa = (char*)malloc(sizeof(char) * (len + 1));
	if (!itoa)
		return ;
	itoa[len] = '\0';
	if (value == 0)
		itoa[0] = '0';
	while (value != 0)
	{
		itoa[--len] = box[value % base];
		value = value / base;
	}
	if (ft_conversion(format) == 'x' || ft_conversion(format) == 'p')
		ft_lower_case(itoa);
	ft_putstr(itoa);
	free(itoa);
}
