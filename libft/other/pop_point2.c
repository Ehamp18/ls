/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_point2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:29:09 by elhampto          #+#    #+#             */
/*   Updated: 2019/09/05 19:16:04 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**pop_point2(char **str, ...)
{
	va_list		val;
	int			i;

	i = -1;
	va_start(val, str);
	while (++i >= 0)
		if (!(str[i] = va_arg(val, char*)))
			break ;
	va_end(val);
	return (str);
}
