/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 10:56:30 by lpellier          #+#    #+#             */
/*   Updated: 2020/01/23 16:21:50 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# define CONVERTER "ciduxXps%"
# include "libft/libft.h"
# include <stdarg.h>

/*
** Infos padding : if 1 -> '0' && if 2 -> '-'
*/

typedef struct		s_printf
{
	int				width;
	int				number;
	int				precision;
	int				padding;
	int				outputlen;
	int				plus;
	int				minus;
	int				space;
	int				perc;
	int				count;
	int				len;
	char			type;
}					t_printf;

/*
**----------------- Filling information -------------------
*/

const char			*checkwidth(const char *format, t_printf *info, va_list ap);
const char			*checkprecision(const char *format, t_printf *info, \
					va_list ap);
const char			*checktype(const char *format, t_printf *info);
const char			*ft_fill_struct(const char *format, t_printf *info, \
					va_list ap);

/*
**--------------------------------------------------------------**
**-------------------------- Output ----------------------------**
**--------------------------------------------------------------**
*/

int					count_format(const char *format);
void				output_flags(t_printf *info);
int					output_sign(t_printf *info, int res);
void				put_zeros(t_printf *info);
void				output_string(t_printf *info, va_list ap);
void				output_int(t_printf *info, va_list ap);
void				output_uint(t_printf *info, va_list ap);
void				output_char(t_printf *info, va_list ap);
void				output_adress(t_printf *info, va_list ap);
void				output_hexmin(t_printf *info, va_list ap);
void				output_hexmax(t_printf *info, va_list ap);
const char			*print_before(const char *format, t_printf *info);
const char			*print_aoutsider(const char *format, t_printf *info);
const char			*init_perc(t_printf *info, const char *format);
void				check_padding_case_int(t_printf *info, int res);
void				check_padding_case_adress(t_printf *info, void *res, \
					char *str);
void				check_padding_case_hex(t_printf *info, void *ret);
void				check_padding_case(t_printf *info);
void				ft_output(t_printf *info, va_list ap);

int					ft_printf(const char *format, ...);

#endif
