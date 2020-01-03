/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 11:52:38 by lpellier          #+#    #+#             */
/*   Updated: 2020/01/03 16:40:34 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	output_flags(t_printf *info, int len)
{
	int		padlength;

	padlength = 0;
	if (info->number == 0 && info->width > len)
		padlength = info->width - len;
	else if (info->number == 1 && info->width > len)
		padlength = (info->width > info->precision && info->precision > len ? \
		info->width - info->precision
		: info->width - len);
	if ((info->plus || info->minus || info->space) && padlength > 0)
		padlength--;
	info->outputlen += padlength;
	if (info->padding != 1 || (info->number == 1 && info->precision != -1))
		while (padlength--)
			ft_putchar_fd(' ', 1);
	else
		while (padlength--)
			ft_putchar_fd('0', 1);
}

void	output_int(t_printf *info, va_list ap)
{
	int		res;
	int		len;

	res = va_arg(ap, int);
	info->minus = (res < 0 ? 1 : 0);
	len = ft_intlen(res);
	info->outputlen += ((info->minus || info->plus) ? len + 1 : len);
	check_padding_case_int(info, res, len);
}

void	output_char(t_printf *info, va_list ap)
{
	char	res;

	if (info->perc == 1)
		res = '%';
	else
		res = va_arg(ap, int);
	info->outputlen += 1;
	if (info->padding == 2)
	{
		ft_putchar_fd(res, 1);
		output_flags(info, 1);
	}
	else
	{
		output_flags(info, 1);
		ft_putchar_fd(res, 1);
	}
}

void	output_adress(t_printf *info, va_list ap)
{
	void				*res;
	int					len;
	long unsigned int	a;
	char				*str;

	a = va_arg(ap, long unsigned int);
	res = ft_lu_hexmin(a);
	if (res == NULL || a == 0)
	{
		len = ft_strlen(res) + 2;
		str = "0x";
	}
	else
	{
		len = ft_strlen(res) + 4;
		str = "0x10";
	}
	info->outputlen += len;
	check_padding_case_adress(info, len, res, str);
}

void	ft_output(t_printf *info, va_list ap)
{
	if (info->precision == 0 && info->number == 1)
	{
		check_padding_case(info);
		return ;
	}
	if (info->type == 'd' || info->type == 'i')
		output_int(info, ap);
	else if (info->type == 's')
		output_string(info, ap);
	else if (info->type == 'u')
		output_uint(info, ap);
	else if (info->type == 'c')
		output_char(info, ap);
	else if (info->type == 'x')
		output_hexmin(info, ap);
	else if (info->type == 'X')
		output_hexmax(info, ap);
	else if (info->type == 'p')
		output_adress(info, ap);
}
