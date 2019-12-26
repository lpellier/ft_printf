/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 10:56:30 by lpellier          #+#    #+#             */
/*   Updated: 2019/12/21 15:17:41 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		LIBFT_PRINTF_H
# define 	LIBFT_PRINTF_H

#include "libft/libft.h"
#include <stdarg.h>

/* Infos padding : if 1 -> '0' && if 2 -> '-'  */

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
	char			type;
}					t_printf;

/*----------------- Filling information -------------------*/

void		checklen(t_printf *info);
const char	*checkwidth(const char *format, t_printf *info, va_list ap);
const char	*checkprecision(const char *format, t_printf *info, va_list ap);
const char	*checktype(const char *format, t_printf *info);
const char	*ft_fill_struct(const char *format, t_printf *info, va_list ap);

/*--------------------------------------------------------------**
**-------------------------- Output ----------------------------**
**--------------------------------------------------------------*/

void		output_flags_number(t_printf *info, int len);
void		output_flags_string(t_printf *info);
void		output_string(t_printf *info, va_list ap);
void		output_int(t_printf *info, va_list ap);
void		output_uint(t_printf *info, va_list ap);
void		output_char(t_printf *info, va_list ap);
void		output_hexmin(t_printf *info, va_list ap);
void		output_hexmax(t_printf *info, va_list ap);
const char	*print_boutsider(const char *format, t_printf *info);
const char	*print_aoutsider(const char *format, t_printf *info);
void		ft_output(t_printf *info, va_list ap);

int		ft_printf(const char *format, ...);

#endif
