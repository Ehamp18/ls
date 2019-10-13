/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 16:01:19 by elhampto          #+#    #+#             */
/*   Updated: 2019/10/04 15:10:23 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			loop(t_bee *btree, t_mod *mod, t_width *check)
{
	char			*tmp;

	if (mod->l)
	{
		tmp = flag_l(btree, check);
		ft_printf("%s\n", tmp);
		free(tmp);
	}
	else
		ft_printf("%s\n", btree->root);
}

static void			printks(t_bee *btree, t_mod *mod, t_width *check)
{
	if (btree->left)
		printks(btree->left, mod, check);
	if (btree->root && mod->a)
		loop(btree, mod, check);
	else
	{
		if (btree->root && ft_strncmp(btree->root, ".", 1) != 0)
			loop(btree, mod, check);
	}
	if (btree->right)
		printks(btree->right, mod, check);
	free(btree);
}

static void			printkr(t_bee *btree, t_mod *mod, t_width *check)
{
	if (btree->right)
		printkr(btree->right, mod, check);
	if (btree->root && mod->a)
		loop(btree, mod, check);
	else
	{
		if (btree->root && ft_strncmp(btree->root, ".", 1) != 0)
			loop(btree, mod, check);
	}
	if (btree->left)
		printkr(btree->left, mod, check);
	free(btree);
}

void				print(t_bee *btree, t_mod *mod, t_width *check)
{
	if (!mod->r)
	{
		if (mod->l)
			ft_printf("total %d\n", check->block);
		printks(btree, mod, check);
	}
	else
	{
		if (mod->l)
			ft_printf("total %d\n", check->block);
		printkr(btree, mod, check);
	}
}
