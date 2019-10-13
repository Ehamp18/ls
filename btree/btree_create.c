/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:17:12 by ehamp             #+#    #+#             */
/*   Updated: 2019/10/04 04:49:17 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_bee			*btree_create(char *item, t_width *check, t_mod *mod)
{
	t_bee		*btree;

	btree = (t_bee*)malloc(sizeof(t_bee));
	lstat(item, &btree->info);
	if (ft_strncmp(item, ".", 1) != 0 && !mod->a)
		check->block += btree->info.st_blocks;
	else if (mod->a)
		check->block += btree->info.st_blocks;
	btree->root = item;
	btree->left = NULL;
	btree->right = NULL;
	return (btree);
}
