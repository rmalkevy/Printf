/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:51:07 by rmalkevy          #+#    #+#             */
/*   Updated: 2016/12/01 19:11:55 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	*ft_wstrsub(wchar_t *s, unsigned int start, size_t len)
{
	wchar_t	*ptr;
	size_t	i;

	i = 0;
	ptr = (wchar_t *)malloc(len + 1);
	if (!ptr || !s)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}
