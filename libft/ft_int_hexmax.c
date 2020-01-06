/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_hexmax.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:32:27 by lpellier          #+#    #+#             */
/*   Updated: 2020/01/06 12:26:29 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_int_hexmax(unsigned int n)
{
	char			*res;
	char			*tab;
	int				i;

	i = 0;
	tab = "0123456789ABCDEF";
	if (!(res = malloc(sizeof(char) * digit_count(n, 16) + 1)))
		return (NULL);
	while (n >= 16)
	{
		res[i] = tab[n % 16];
		n /= 16;
		i++;
	}
	res[i] = tab[n];
	return (ft_strrev(res));
}
