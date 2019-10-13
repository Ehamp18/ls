/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 21:32:27 by elhampto          #+#    #+#             */
/*   Updated: 2019/10/04 16:18:17 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <time.h>
# include <errno.h>

typedef struct		s_bee
{
	struct stat		info;
	int				i;
	char			*root;
	struct s_bee	*left;
	struct s_bee	*right;
}					t_bee;

typedef struct		s_width
{
	int				block;
	int				link;
	int				size;
	int				rand;
}					t_width;

typedef struct		s_mod
{
	int				l;
	int				a;
	int				ur;
	int				r;
	int				t;
	struct stat		info;
	int				i;
	char			*root;
	struct s_dire	*next;
}					t_mod;

void				flag_check(t_mod *mod, char **str);
void				split(t_bee **btr, t_mod *mo, DIR *dir, t_width **check);
void				ft_ls(DIR *dir, t_mod *mod);
void				print(t_bee *btree, t_mod *mod, t_width *check);
t_bee				*btree_create(char *item, t_width *check, t_mod *mod);
void				btree_insert(t_bee *btree, t_bee *b2, t_mod *mod);
char				*flag_l(t_bee *btree, t_width *check);
void				flag_ur(t_bee *btree, t_mod *mod);
char				*time_check(t_bee *btree, char *str, t_width *check);
char				*bitsize(t_bee *btree, char *new, t_width *check);

#endif
