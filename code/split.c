/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 15:46:36 by elhampto          #+#    #+#             */
/*   Updated: 2019/10/04 04:48:31 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#define INFO (*btr)->info

void	split(t_bee **btr, t_mod *mo, DIR *dir, t_width **check)
{
	struct dirent	*list;
	t_bee			*btr2;

	list = readdir(dir);
	*btr = btree_create(list->d_name, *check, mo);
	(*check)->block = INFO.st_blocks;
	(*check)->link = ft_numlen(INFO.st_nlink);
	(*check)->size = ft_numlen(INFO.st_size);
	(*check)->rand = ft_numlen(INFO.st_mtime);
	while ((list = readdir(dir)))
	{
		if (ft_numlen(INFO.st_nlink) > (*check)->link)
			(*check)->link = ft_numlen(INFO.st_nlink);
		if (ft_numlen(INFO.st_size) > (*check)->size)
			(*check)->size = ft_numlen(INFO.st_size);
		if (ft_numlen(INFO.st_mtime) > (*check)->rand)
			(*check)->rand = ft_numlen(INFO.st_mtime);
		btr2 = btree_create(list->d_name, *check, mo);
		btree_insert(*btr, btr2, mo);
	}
	closedir(dir);
}
