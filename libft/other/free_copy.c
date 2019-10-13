/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 04:58:38 by elhampto          #+#    #+#             */
/*   Updated: 2019/09/19 00:28:16 by elhampto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*free_copy(char *com, char *tmp)
{
	free(tmp);
	ft_bzero(tmp, ft_strlen(tmp));
	tmp = ft_strjoin(tmp, com);
	free(com);
	return (tmp);
}
