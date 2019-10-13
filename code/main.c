/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 21:02:27 by elhampto          #+#    #+#             */
/*   Updated: 2019/10/04 20:58:00 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			min(char **av, int i)
{
	int				j;

	j = 0;
	while (av[i][++j])
		if (av[i][j] != 'a' && av[i][j] != 't' && av[i][j] != 'r' &&
			av[i][j] != 'l')
		{
			ft_printf("Error: %c is not a flag!\n", av[i][j]);
			ft_printf("Valid flags: [a, r, t, l]\n");
			return (1);
		}
	return (0);
}

static int			error_check(char **av, int i, t_mod *mod)
{
	DIR				*dir;

	while (av[++i])
	{
		if (av[i][0] != '-')
		{
			if (!(dir = opendir(av[i])))
			{
				ft_printf("Error: %s\n", strerror(errno));
				return (0);
			}
			ft_printf("%s:\n", av[i]);
			ft_ls(dir, mod);
			return (2);
		}
		else if (av[i][0] == '-')
		{
			if (min(av, i) == 1)
				return (0);
		}
	}
	return (1);
}

int					main(int ac, char **av)
{
	DIR				*dir;
	t_mod			mod;
	int				i;

	ft_bzero(&mod, sizeof(mod));
	if (ac == 1)
	{
		dir = opendir(".");
		ft_ls(dir, &mod);
	}
	else
	{
		flag_check(&mod, av);
		i = 0;
		i = error_check(av, i, &mod);
		if (i == 1)
		{
			dir = opendir(".");
			ft_ls(dir, &mod);
		}
	}
	return (0);
}
