/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellier <lpellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 14:50:42 by lpellier          #+#    #+#             */
/*   Updated: 2019/12/02 15:21:09 by lpellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		len;
	char	temp;
	int		i;
	int		count;

	len = ft_strlen(str) - 1;
	i = 0;
	count = len;
	while (count - i / 2 > 0)
	{
		temp = str[i];
		str[i] = str[len - i];
		str[len - i] = temp;
		i++;
		count--;
	}
	return (str);
}
