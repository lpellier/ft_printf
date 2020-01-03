/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_other.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:34:26 by lpellier          #+#    #+#             */
/*   Updated: 2020/01/03 16:40:34 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	output_string(t_printf *info, va_list ap)
{
	char	*res;
	int		len;

	res = va_arg(ap, char *);
	if (res == NULL)
		res = "(null)";
	len = res == NULL ? 6 : ft_strlen(res);
	if (info->precision > info->width && info->width != 0)
		info->precision = -1;
	len = (info->precision < len && info->precision != -1 ? \
	info->precision : len);
	info->outputlen += len;
	if (info->padding == 2)
	{
		ft_putnstr_fd(res, len, 1);
		output_flags(info, len);
	}
	else
	{
		output_flags(info, len);
		ft_putnstr_fd(res, len, 1);
	}
}

void	output_uint(t_printf *info, va_list ap)
{
	unsigned int	res;
	int				len;

	res = va_arg(ap, int);
	len = ft_intlen(res);
	info->outputlen += (info->plus ? len + 1 : len);
	if (info->padding == 2)
	{
		put_zeros(info, len);
		ft_putunbr_fd(res, 1);
		output_flags(info, len);
	}
	else if (info->padding == 1)
	{
		output_flags(info, len);
		put_zeros(info, len);
		ft_putunbr_fd(res, 1);
	}
	else
	{
		output_flags(info, len);
		put_zeros(info, len);
		ft_putunbr_fd(res, 1);
	}
}

void	output_hexmin(t_printf *info, va_list ap)
{
	char	*res;
	int		len;

	res = ft_int_hexmin(va_arg(ap, int));
	len = ft_strlen(res);
	info->outputlen += len;
	if (info->padding == 2)
	{
		put_zeros(info, len);
		ft_putnstr_fd(res, len, 1);
		output_flags(info, len);
	}
	else if (info->padding == 1)
	{
		output_flags(info, len);
		put_zeros(info, len);
		ft_putnstr_fd(res, len, 1);
	}
	else
	{
		output_flags(info, len);
		put_zeros(info, len);
		ft_putnstr_fd(res, len, 1);
	}
}

void	output_hexmax(t_printf *info, va_list ap)
{
	char	*res;
	int		len;

	res = ft_int_hexmax(va_arg(ap, int));
	len = ft_strlen(res);
	info->outputlen += len;
	if (info->padding == 2)
	{
		put_zeros(info, len);
		ft_putnstr_fd(res, len, 1);
		output_flags(info, len);
	}
	else if (info->padding == 1)
	{
		output_flags(info, len);
		put_zeros(info, len);
		ft_putnstr_fd(res, len, 1);
	}
	else
	{
		output_flags(info, len);
		put_zeros(info, len);
		ft_putnstr_fd(res, len, 1);
	}
}
