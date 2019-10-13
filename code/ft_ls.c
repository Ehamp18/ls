/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 15:58:51 by elhampto          #+#    #+#             */
/*   Updated: 2019/10/04 04:38:18 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#define TIME btree->info.st_mtime
#define SIZE btree->info.st_size

char				*time_check(t_bee *btree, char *str, t_width *check)
{
	char			*res;
	char			*tmp;
	char			*new;

	new = ft_strnew(check->rand);
	res = ctime(&TIME);
	tmp = ft_strsub(res, 3, ft_strlen(res) - 12);
	ft_strcat(new, tmp);
	free(tmp);
	res = ft_strjoin(str, new);
	free(new);
	new = ft_strjoin(res, " ");
	free(res);
	return (new);
}

char				*bitsize(t_bee *btree, char *new, t_width *check)
{
	char			*res;
	char			*tmp;
	char			*tmp2;

	res = ft_itoa(SIZE);
	tmp = (char*)ft_memalloc(check->size + 1);
	ft_memset(tmp, ' ', (check->size + 2 - ft_strlen(res)));
	tmp2 = ft_strjoin(tmp, res);
	free(tmp);
	free(res);
	tmp = ft_strjoin(new, tmp2);
	free(tmp2);
	return (tmp);
}

void				ft_ls(DIR *dir, t_mod *mod)
{
	t_bee			*btree;
	t_width			*check;

	btree = NULL;
	check = (t_width*)ft_memalloc(sizeof(t_width));
	split(&btree, mod, dir, &check);
	print(btree, mod, check);
	if (mod->ur)
		ft_printf("Error: Service not in order\n");
	free(check);
}
