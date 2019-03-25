/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   place_tet.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 16:51:36 by lgutter        #+#    #+#                */
/*   Updated: 2019/03/24 18:46:18 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		place_tet(unsigned int *tet, unsigned short *map, unsigned short di)
{
	while (check_hash(1, *tet, map, di) != 1 ||
			check_hash(2, *tet, map, di) != 1 ||
			check_hash(3, *tet, map, di) != 1 ||
			check_hash(4, *tet, map, di) != 1)
	{
		if (increment_offset(tet, di) == -1)
			return (-1);
	}
	place_final(*tet, map);
	return (1);
}
