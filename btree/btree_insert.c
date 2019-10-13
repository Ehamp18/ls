/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:32:43 by ehamp             #+#    #+#             */
/*   Updated: 2019/10/04 04:26:33 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#define TIME btre->info.st_mtimespec
#define TIME2 b2->info.st_mtimespec

void		btree_insert(t_bee *btre, t_bee *b2, t_mod *mod)
{
	if (mod->t && TIME.tv_sec > TIME2.tv_sec)
		btre->right ? btree_insert(btre->right, b2, mod) : (btre->right = b2);
	else if (mod->t && TIME.tv_sec < TIME2.tv_sec)
		btre->left ? btree_insert(btre->left, b2, mod) : (btre->left = b2);
	else if (mod->t && TIME.tv_sec == TIME2.tv_sec
					&& TIME.tv_nsec > TIME2.tv_nsec)
		btre->right ? btree_insert(btre->right, b2, mod) : (btre->right = b2);
	else if (mod->t && TIME.tv_sec == TIME2.tv_sec
					&& TIME.tv_nsec < TIME2.tv_nsec)
		btre->left ? btree_insert(btre->left, b2, mod) : (btre->left = b2);
	else if (ft_strcmp(b2->root, btre->root) >= 0)
		btre->right ? btree_insert(btre->right, b2, mod) : (btre->right = b2);
	else if (ft_strcmp(b2->root, btre->root) < 0)
		btre->left ? btree_insert(btre->left, b2, mod) : (btre->left = b2);
}
