/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 11:52:38 by lpellier          #+#    #+#             */
/*   Updated: 2019/12/26 14:23:47 by lpellier         ###   ########.fr       */
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
		padlength = (info->width > info->precision && info->precision > len ? info->width - info->precision
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

void	output_string(t_printf *info, va_list ap)
{
	char	*res;
	int		len;

	res = va_arg(ap, char *);
	if (res == NULL)
		res = "(null)";
	if (info->precision > info->width && info->width != 0)
		info->precision = -1;
	len = ft_strlen(res);
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

void	put_zeros(t_printf *info, int len)
{
	int		new;

	if (info->precision > len)
	{
		new = info->precision - len;
		while (new--)
		{
			ft_putchar_fd('0', 1);
			info->outputlen++;
		}
	}
}

int		output_sign(t_printf *info, int res)
{
	int count;

	if (info->minus)
	{
		ft_putchar_fd('-', 1);
		res *= -1;
	}
	else if (info->plus)
		ft_putchar_fd('+', 1);
	else if (info->space)
	{
		ft_putchar_fd(' ', 1);
		info->outputlen += 1;
	}
	return (res);
}

void	output_int(t_printf *info, va_list ap)
{
	int		res;
	int		len;

	res = va_arg(ap, int);
	info->minus = (res < 0 ? 1 : 0);
	len = ft_intlen(res);
	info->outputlen += ((info->minus || info->plus) ? len + 1 : len);
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
	format++;
	return (&(*format));
}

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

void	output_adress(t_printf *info, va_list ap)
{
	void				*res;
	int					len;
	long unsigned int	a;

	res = ft_lu_hexmin(va_arg(ap, long unsigned int));
	len = ft_strlen(res) + 2;
	info->outputlen += len;
	if (info->padding == 2)
	{
		put_zeros(info, len);
		ft_putstr_fd("0x", 1);
		ft_putnstr_fd(res, len, 1);
		output_flags(info, len);
	}
	else
	{
		output_flags(info, len);
		put_zeros(info, len);
		ft_putstr_fd("0x", 1);
		ft_putnstr_fd(res, len, 1);
	}
}

void	ft_output(t_printf *info, va_list ap)
{
	if (info->precision == 0 && info->number == 1)
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
