/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 00:07:19 by elhampto          #+#    #+#             */
/*   Updated: 2019/10/04 04:42:36 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#define DATA btree->info.st_mode
#define LINK btree->info.st_nlink
#define UID btree->info.st_uid
#define GID btree->info.st_gid

static char			help(t_bee *btree, char *per)
{
	S_ISDIR(DATA) ? per[0] = 'd' : 0;
	S_ISBLK(DATA) ? per[0] = 'b' : 0;
	S_ISLNK(DATA) ? per[0] = 'l' : 0;
	S_ISREG(DATA) ? per[0] = '-' : 0;
	S_ISCHR(DATA) ? per[0] = 'c' : 0;
	S_ISFIFO(DATA) ? per[0] = 'p' : 0;
	S_ISSOCK(DATA) ? per[0] = 's' : 0;
	return (per[0]);
}

static char			*permissions(t_bee *btree)
{
	static char		per[12];

	ft_bzero(per, 12);
	per[0] = help(btree, per);
	per[1] = (DATA & S_IRUSR) ? 'r' : '-';
	per[2] = (DATA & S_IWUSR) ? 'w' : '-';
	per[3] = (DATA & S_IXUSR) ? 'x' : '-';
	per[4] = (DATA & S_IRGRP) ? 'r' : '-';
	per[5] = (DATA & S_IWGRP) ? 'w' : '-';
	per[6] = (DATA & S_IXGRP) ? 'x' : '-';
	per[7] = (DATA & S_IROTH) ? 'r' : '-';
	per[8] = (DATA & S_IWOTH) ? 'w' : '-';
	per[9] = (DATA & S_IXOTH) ? 'x' : '-';
	if (DATA & S_ISUID)
		per[3] = ((DATA & S_IXUSR) ? 's' : 'S');
	if (DATA & S_ISGID)
		per[6] = ((DATA & S_IXGRP) ? 's' : 'l');
	if (DATA & S_ISVTX)
		per[9] = ((DATA & S_IXOTH) ? 't' : 'T');
	per[10] = ' ';
	per[11] = ' ';
	return (per);
}

static char			*num_links(t_bee *btree, char *new, t_width *check)
{
	char			*str;
	char			*res;
	char			*res2;

	res = ft_itoa(LINK);
	str = (char*)ft_memalloc(check->link + 1);
	ft_memset(str, ' ', (check->link + 1 - ft_strlen(res)));
	res2 = ft_strjoin(str, res);
	free(res);
	res = ft_strjoin(new, res2);
	free(res2);
	free(str);
	return (res);
}

static char			*the_uids(t_bee *btree, char *new)
{
	char			*fin;
	char			*tmp;
	char			*tmp2;
	struct passwd	str;
	struct group	grp;

	str = *getpwuid(UID);
	grp = *getgrgid(GID);
	fin = ft_strjoin(" ", str.pw_name);
	tmp = ft_strjoin(new, fin);
	free(fin);
	fin = ft_strjoin("  ", grp.gr_name);
	tmp2 = ft_strjoin(tmp, fin);
	free(tmp);
	free(fin);
	tmp = ft_strjoin(tmp2, " ");
	free(tmp2);
	return (tmp);
}

char				*flag_l(t_bee *btree, t_width *check)
{
	char			*new;
	char			*tmp;

	tmp = ft_strnew(sizeof(char));
	new = permissions(btree);
	new = num_links(btree, new, check);
	tmp = free_copy(new, tmp);
	new = the_uids(btree, tmp);
	tmp = free_copy(new, tmp);
	new = bitsize(btree, tmp, check);
	tmp = free_copy(new, tmp);
	new = time_check(btree, tmp, check);
	free(tmp);
	tmp = ft_strjoin(new, btree->root);
	free(new);
	return (tmp);
}
