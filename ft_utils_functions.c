/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:36:54 by lpellier          #+#    #+#             */
/*   Updated: 2020/01/03 16:37:39 by lpellier         ###   ########.fr       */
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
