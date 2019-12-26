/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 10:29:31 by lpellier          #+#    #+#             */
/*   Updated: 2019/12/21 15:16:24 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

const char	*checkflags(const char *format, t_printf *info)
{
	while (*format == '-' || *format == '0' || *format == '+')
	{
		if (*format == '+')
		{
			info->plus += 1;
			while (*format == '+')
				format++;
			format--;
		}
		if (*format == '-' && *(format + 1) == '0')
			info->padding = 2;
		else if (*format == '0' && *(format + 1) != '-' && *(format - 1) != '-')
			info->padding = 1;
		else if (*format == '-' && *(format + 1) != '0' && *(format + 1) != '0')
			info->padding = 2;
		format++;
	}
	return (&(*format));
}

const char	*checkwidth(const char *format, t_printf *info, va_list ap)
{
	if (*format >= '0' && *format <= '9')
	{
		while (*format >= '0' && *format <= '9')
		{
			info->width = info->width * 10 + *format - 48;
			format++;
		}
	}
	else if (*format == '*')
	{
		info->width = va_arg(ap, int);
		format++;
	}
	return (&(*format));
}

const char	*checkprecision(const char *format, t_printf *info, va_list ap)
{
	if (*format == '.')
	{
		info->precision = 0;
		format++;
		if (*format >= '0' && *format <= '9')
		{
			while (*format >= '0' && *format <= '9')
			{
				info->precision = info->precision * 10 + *format - 48;
				format++;
			}
		}
		else if (*format == '*')
		{
			info->precision = va_arg(ap, int);
			format++;
		}
	}
	return (&(*format));
}

const char	*checktype(const char *format, t_printf *info)
{
	if (*format == 'p' || *format == 'd' || *format == 'i'
	|| *format == 'u' || *format == 'x' || *format == 'X')
	{
		info->type = *format;
		info->number = 1;
		format++;
	}
	else if (*format == 'c' || *format == 's')
	{
		info->type = *format;
		info->number = 0;
		format++;
	}
	else if (*format == '%')
	{
		info->type = 'c';
		info->number = 0;
		info->perc = 1;
		format++;
	}
	return (&(*format));
}

const char	*ft_fill_struct(const char *format, t_printf *info, va_list ap)
{
	if (*format == '+')
	{
		info->plus += 1;
		while (*format == '+')
			format++;
	}
	if (*format == ' ')
	{
		info->space += 1;
		while (*format == ' ')
			format++;
	}
	format = checkflags(&(*format), info);
	format = checkwidth(&(*format), info, ap);
	format = checkprecision(&(*format), info, ap);
	format = checktype(&(*format), info);
//	printf("%s%d\n", "width = ", info->width);
//	printf("%s%d\n", "precision = ", info->precision);
//	printf("%s%d\n", "padding = ", info->padding);
//	printf("%s%c\n", "type = ", info->type);
	return (&(*format));
}