/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxiliary_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:28:16 by lpellier          #+#    #+#             */
/*   Updated: 2020/01/03 17:39:41 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

const char	*print_aoutsider(const char *format, t_printf *info)
{
	while (*format != '%' && *format)
	{
		ft_putchar_fd(*format, 1);
		info->outputlen += 1;
		format++;
	}
	return (&(*format));
}

const char	*print_boutsider(const char *format, t_printf *info)
{
	if (*format != '%')
	{
		while (*format != '%' && *format)
		{
			ft_putchar_fd(*format, 1);
			info->outputlen += 1;
			format++;
		}
	}
	if (*format == '%' && *(format + 1) != '%')
		format++;
	return (&(*format));
}

void		check_padding_case_int(t_printf *info, int res, int len)
{
	if (info->padding == 2)
	{
		res = output_sign(info, res);
		put_zeros(info, len);
		ft_putnbr_fd(res, 1);
		output_flags(info, len);
	}
	else if (info->padding == 1)
	{
		res = (info->precision == -1 ? output_sign(info, res) : res);
		output_flags(info, len);
		res = (info->precision != -1 ? output_sign(info, res) : res);
		put_zeros(info, len);
		ft_putnbr_fd(res, 1);
	}
	else
	{
		output_flags(info, len);
		res = output_sign(info, res);
		put_zeros(info, len);
		ft_putnbr_fd(res, 1);
	}
}

void		check_padding_case_adress(t_printf *info, int len, void *res, \
			char *str)
{
	if (info->padding == 2)
	{
		put_zeros(info, len);
		ft_putstr_fd(str, 1);
		ft_putnstr_fd(res, len, 1);
		output_flags(info, len);
	}
	else
	{
		output_flags(info, len);
		put_zeros(info, len);
		ft_putstr_fd(str, 1);
		ft_putnstr_fd(res, len, 1);
	}
}

void		check_padding_case(t_printf *info)
{
	if (info->padding == 2)
	{
		output_sign(info, 0);
		output_flags(info, 0);
	}
	else
	{
		output_flags(info, 0);
		output_sign(info, 0);
	}
}
