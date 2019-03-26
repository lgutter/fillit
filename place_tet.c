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

static int	check_hash(short hash, unsigned int tet, unsigned short *map,\
			   unsigned short di)
{
	unsigned char	y;
	unsigned char	x;
	
	hash = 0;
	while (hash <= 12)
	{
		y = (((tet >> 16) & 255) + ((tet >> (hash) & 3)));
		x = ((tet >> 24) + ((tet >> ((hash) + 2)) & 3));
		if (x >= di || y >= di || ((map[y] >> x) & 1) != 0)
			return (-1);
		hash += 4;
	}
	return (1);
}

int			place_tet(unsigned int *tet, unsigned short *map, unsigned short di)
{
	while (check_hash(0, *tet, map, di) != 1)
	{
		if (increment_offset(tet, di) == -1)
			return (-1);
	}
	place_final(*tet, map);
	return (1);
}
