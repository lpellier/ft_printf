/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_hexmin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 14:17:14 by lpellier          #+#    #+#             */
/*   Updated: 2020/01/08 18:36:47 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_int_hexmin(long n, char *tab)
{
	char			*res;
	int				taille;
	int				i;

	if (n < 0)
		return (ft_int_hexmin((-n - 1), "fedcba9876543210"));
	i = 0;
	taille = digit_count(n, 16);
	if (!(res = (char *)calloc(1, (sizeof(char) * (taille + 1)))))
		return (NULL);
	taille--;
	while (n)
	{
		res[taille - i++] = tab[n % 16];
		n /= 16;
	}
	return (res);
}
