/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 23:20:38 by elhampto          #+#    #+#             */
/*   Updated: 2019/09/22 01:36:56 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#define I i[0]
#define J i[1]

void		flag_check(t_mod *mod, char **str)
{
	int		i[3];

	J = -1;
	while (str[++J])
		if (*str[J] == '-')
		{
			I = -1;
			while (str[J][++I])
			{
				if (str[J][I] == 'a')
					mod->a = 97;
				if (str[J][I] == 'l')
					mod->l = 108;
				if (str[J][I] == 'r')
					mod->r = 114;
				if (str[J][I] == 'R')
					mod->ur = 82;
				if (str[J][I] == 't')
					mod->t = 116;
			}
			str += ++J;
			J = -1;
		}
}
