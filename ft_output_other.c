/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_other.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:34:26 by lpellier          #+#    #+#             */
/*   Updated: 2020/01/06 16:34:32 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <string.h>

void	output_string(t_printf *info, va_list ap)
{
	char	*res;

	res = va_arg(ap, char *);
	if (res == NULL)
		res = "(null)";
	info->len = (res == NULL ? 6 : strlen(res));
	if (info->precision > info->width && info->width != 0)
		info->precision = -1;
	info->len = (info->precision < info->len && info->precision != -1 ? \
	info->precision : info->len);
	info->outputlen += info->len;
	if (info->padding == 2)
	{
		ft_putnstr_fd(res, info->len, 1);
		output_flags(info);
	}
	else
	{
		output_flags(info);
		ft_putnstr_fd(res, info->len, 1);
	}
}

void	output_uint(t_printf *info, va_list ap)
{
	unsigned int	res;

	res = va_arg(ap, int);
	info->len = ft_uintlen(res);
	info->outputlen += (info->plus ? info->len + 1 : info->len);
	if (info->padding == 2)
	{
		put_zeros(info);
		ft_putunbr_fd(res, 1);
		output_flags(info);
	}
	else if (info->padding == 1)
	{
		output_flags(info);
		put_zeros(info);
		ft_putunbr_fd(res, 1);
	}
	else
	{
		output_flags(info);
		put_zeros(info);
		ft_putunbr_fd(res, 1);
	}
}

void	output_hexmin(t_printf *info, va_list ap)
{
	char	*res;

	res = ft_int_hexmin(va_arg(ap, int));
	info->len = ft_strlen(res);
	info->outputlen += info->len;
	if (info->padding == 2)
	{
		put_zeros(info);
		ft_putnstr_fd(res, info->len, 1);
		output_flags(info);
	}
	else if (info->padding == 1)
	{
		output_flags(info);
		put_zeros(info);
		ft_putnstr_fd(res, info->len, 1);
	}
	else
	{
		output_flags(info);
		put_zeros(info);
		ft_putnstr_fd(res, info->len, 1);
	}
}

void	output_hexmax(t_printf *info, va_list ap)
{
	char	*res;

	res = ft_int_hexmax(va_arg(ap, int));
	info->len = ft_strlen(res);
	info->outputlen += info->len;
	if (info->padding == 2)
	{
		put_zeros(info);
		ft_putnstr_fd(res, info->len, 1);
		output_flags(info);
	}
	else if (info->padding == 1)
	{
		output_flags(info);
		put_zeros(info);
		ft_putnstr_fd(res, info->len, 1);
	}
	else
	{
		output_flags(info);
		put_zeros(info);
		ft_putnstr_fd(res, info->len, 1);
	}
}
