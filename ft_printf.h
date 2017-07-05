/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 10:49:03 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/02/03 16:10:22 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF_H
# define __FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int g_star;
int g_minus;

typedef struct	s_shape
{
	int			precision;
	int			width;
	int			conversion;
	int			plus_space;
	int			minus;
	int			len_num;
	int			zero;
	char		*sharp;
}				t_struct;
int				ft_printf(char *format, ...);
t_struct		*ft_create_struct();
void			ft_function(char *format, va_list ap);
int				ft_distributor(char *format, int i, va_list ap);
t_struct		*ft_flags(char *format, uintmax_t num, int base, t_struct *mod);
int				ft_zero_prec(char *format, uintmax_t num, t_struct *mod);
void			ft_itoa_base_unsigned(char *format, uintmax_t value, int base);
int				ft_len_num(uintmax_t value, int base);
int				ft_end_format(char *format, int i);
void			ft_string(char *format, va_list ap);
int				ft_precision(char *format);
int				ft_plus_space(char *format);
int				ft_minus(char *format);
int				ft_width(char *format);
int				ft_zero(char *format);
int				ft_conversion(char *format);
char			*ft_sharp(char *format, uintmax_t num, t_struct *mod);
char			*ft_lower_case(char *number);
void			ft_print_symbol(int count, int symbol);
void			ft_print_width(t_struct *mod);
int				ft_find_flag(char *format, int c);
void			ft_10(char *format, va_list ap);
void			ft_u10(char *format, va_list ap);
void			ft_16(char *format, va_list ap);
void			ft_8(char *format, va_list ap);
void			ft_pointer(char *format, va_list ap);
int				ft_zero_string(char *format);
void			ft_char(char *format, va_list ap);
int				ft_atoi(const char *str);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
char			*ft_strdup(const char *str);
size_t			ft_strlen(const char *str);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				ft_tolower(int c);
void			ft_putnbr(uintmax_t num);
void			ft_number_printed_symbols(va_list ap);
void			ft_u2(char *format, va_list ap);
void			ft_putwchar(wchar_t symbol);
char			*ft_strnew(size_t size);
void			ft_strdel(char **str);
void			ft_wchar(char *format, va_list ap);
void			ft_putwstr(wchar_t *s);
size_t			ft_wstrlen(wchar_t *str);
wchar_t			*ft_wstrsub(wchar_t *s, unsigned int start, size_t len);
void			ft_wstring(char *format, va_list ap);
void			ft_print_string(char *format, char *string);

#endif
