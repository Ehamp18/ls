/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bulk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 16:01:19 by elhampto          #+#    #+#             */
/*   Updated: 2019/09/05 22:11:25 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			printks(t_bee *btree, t_mod *mod)
{
	if (btree->left)
		printks(btree->left, mod);
	if (mod->l)
		flag_l(btree);
	if (btree->root && mod->a)
		ft_printf("%s\n", btree->root);
	else
	{
		if (btree->root && ft_strncmp(btree->root, ".", 1) != 0)
			ft_printf("%s\n", btree->root);
	}
	if (btree->right)
		printks(btree->right, mod);
	free(btree);
}

static void			printkr(t_bee *btree, t_mod *mod)
{
	if (btree->right)
		printkr(btree->right, mod);
	if (mod->l)
		flag_l(btree);
	if (btree->root && mod->a)
		ft_printf("%s\n", btree->root);
	else
	{
		if (btree->root && ft_strncmp(btree->root, ".", 1) != 0)
			ft_printf("%s\n", btree->root);
	}
	if (btree->left)
		printkr(btree->left, mod);
	free(btree);
}

void				bulk(t_bee *btree, t_mod *mod)
{
	if (mod->ur == 82)
		flag_ur(btree, mod);
	if (!mod->r)
		printks(btree, mod);
	else
		printkr(btree, mod);
}
