/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:36:54 by lpellier          #+#    #+#             */
/*   Updated: 2020/01/06 14:41:54 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

void	put_zeros(t_printf *info)
{
	int		new;

	if (info->precision > info->len)
	{
		new = info->precision - info->len;
		while (new--)
		{
			ft_putchar_fd('0', 1);
			info->outputlen++;
		}
	}
}

const char	*init_perc(t_printf *info, const char *format)
{
	info->type = 'c';
	info->number = 0;
	info->perc = 1;
	info->count++;
	format += 1;
	return (format);
}
