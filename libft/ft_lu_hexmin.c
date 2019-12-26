/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lu_hexmin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 14:40:26 by lpellier          #+#    #+#             */
/*   Updated: 2019/12/26 14:26:38 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lu_hexmin(long unsigned int n)
{
	char			*res;
	char			*tab;
	int				i;

	i = 0;
	tab = "0123456789abcdef";
	if (!(res = malloc(sizeof(char) * digit_count(n, 16) + 1)))
		return (NULL);
	while (n > 16)
	{
		res[i] = tab[n % 16];
		n /= 16;
		i++;
	}
	res[i] = tab[n];
	return (ft_strrev(res));
}
