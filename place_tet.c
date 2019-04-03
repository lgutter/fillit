/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   place_tet.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 16:51:36 by lgutter        #+#    #+#                */
/*   Updated: 2019/03/31 19:09:10 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	place_final(unsigned int tet, unsigned short *map)
{
	unsigned char	y;
	unsigned char	x;

	y = (((tet >> 16) & 255) + ((tet >> 0) & 3));
	x = ((tet >> 24) + ((tet >> ((0) + 2)) & 3));
	map[y] = map[y] | (1 << x);
	y = (((tet >> 16) & 255) + ((tet >> 4) & 3));
	x = ((tet >> 24) + ((tet >> ((4) + 2)) & 3));
	map[y] = map[y] | (1 << x);
	y = (((tet >> 16) & 255) + ((tet >> 8) & 3));
	x = ((tet >> 24) + ((tet >> ((8) + 2)) & 3));
	map[y] = map[y] | (1 << x);
	y = (((tet >> 16) & 255) + ((tet >> 12) & 3));
	x = ((tet >> 24) + ((tet >> ((12) + 2)) & 3));
	map[y] = map[y] | (1 << x);
}

static int	check_hash(unsigned int tet, unsigned short *map,\
			unsigned short di)
{
	unsigned char	y;
	unsigned char	x;

	y = (((tet >> 16) & 255) + ((tet >> (0) & 3)));
	x = ((tet >> 24) + ((tet >> ((0) + 2)) & 3));
	if (x >= di || y >= di || ((map[y] >> x) & 1) != 0)
		return (-1);
	y = (((tet >> 16) & 255) + ((tet >> (12) & 3)));
	x = ((tet >> 24) + ((tet >> ((12) + 2)) & 3));
	if (x >= di || y >= di || ((map[y] >> x) & 1) != 0)
		return (-1);
	y = (((tet >> 16) & 255) + ((tet >> (8) & 3)));
	x = ((tet >> 24) + ((tet >> ((8) + 2)) & 3));
	if (x >= di || y >= di || ((map[y] >> x) & 1) != 0)
		return (-1);
	y = (((tet >> 16) & 255) + ((tet >> (4) & 3)));
	x = ((tet >> 24) + ((tet >> ((4) + 2)) & 3));
	if (x >= di || y >= di || ((map[y] >> x) & 1) != 0)
		return (-1);
	return (1);
}

int			place_tet(unsigned int *tet, unsigned short *map,\
			unsigned short di)
{
	while (check_hash(*tet, map, di) != 1)
	{
		if (increment_offset(tet, di, map) == -1)
			return (-1);
	}
	place_final(*tet, map);
	return (1);
}
