/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:17:07 by elhampto          #+#    #+#             */
/*   Updated: 2019/08/12 21:08:05 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int64_t n)
{
	const char	index[10] = "0123456789";
	int			len;
	int64_t		a;
	char		*asc;

	ZERO(!(asc = ft_strnew(ft_numlen(n))));
	asc[0] = '0';
	if (n == 0)
		return (asc);
	a = n;
	len = (n <= 0) ? 1 : 0;
	while (a)
	{
		len++;
		a /= 10;
	}
	a = n;
	NEG_CHECK(a);
	while (len--)
	{
		asc[len] = index[a % 10];
		a /= 10;
	}
	NEG_SI_PRNT(n, asc[0]);
	return (asc);
}
