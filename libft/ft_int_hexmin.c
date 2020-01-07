/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_hexmin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 14:17:14 by lpellier          #+#    #+#             */
/*   Updated: 2020/01/06 12:26:33 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_int_hexmin(unsigned int n)
{
	char			*res;
	char			*tab;
	int			taille;
	int				i;

	i = 0;
	taille = digit_count(n, 16);
	tab = ft_strdup("0123456789abcdef");
	if (!(res = (char *)calloc(1, (sizeof(char) * (taille + 1)))))
	{
		free(tab);
		return (NULL);
	}
	taille--;
	while (n)
	{
		res[taille - i++] = tab[n % 16];
		n /= 16;
	}
	free(tab);
	return (res);
}

