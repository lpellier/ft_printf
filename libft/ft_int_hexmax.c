/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_hexmax.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:32:27 by lpellier          #+#    #+#             */
/*   Updated: 2020/01/08 18:37:10 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_int_hexmax(long n, char *tab)
{
	char			*res;
	int				taille;
	int				i;

	if (n < 0)
		return (ft_int_hexmax((-n - 1), "FEDCBA9876543210"));
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
