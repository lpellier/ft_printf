/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 10:56:30 by lpellier          #+#    #+#             */
/*   Updated: 2020/01/03 16:44:35 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

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
	char			type;
}					t_printf;

/*
**----------------- Filling information -------------------
*/

void				checklen(t_printf *info);
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

void				output_flags(t_printf *info, int len);
int					output_sign(t_printf *info, int res);
void				put_zeros(t_printf *info, int len);
void				output_string(t_printf *info, va_list ap);
void				output_int(t_printf *info, va_list ap);
void				output_uint(t_printf *info, va_list ap);
void				output_char(t_printf *info, va_list ap);
void				output_adress(t_printf *info, va_list ap);
void				output_hexmin(t_printf *info, va_list ap);
void				output_hexmax(t_printf *info, va_list ap);
const char			*print_boutsider(const char *format, t_printf *info);
const char			*print_aoutsider(const char *format, t_printf *info);
void				check_padding_case_int(t_printf *info, int res, int len);
void				check_padding_case_adress(t_printf *info, int len, \
					void *res, char *str);
void				check_padding_case(t_printf *info);
void				ft_output(t_printf *info, va_list ap);

int					ft_printf(const char *format, ...);

#endif
