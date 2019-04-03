/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   remove_tet.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 16:59:04 by lgutter        #+#    #+#                */
/*   Updated: 2019/03/24 18:45:39 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	remove_tet(unsigned int *tet, unsigned short *map, unsigned short di)
{
	unsigned char	*offx;
	unsigned char	*offy;
	short			hash;

	hash = 0;
	offx = (unsigned char *)(tet) + 3;
	offy = (unsigned char *)(tet) + 2;
	while (hash < 4)
	{
		map[(*offy + ((*tet >> (hash * 4)) & 3))] &= \
		(65535 - (1 << (*offx + ((*tet >> (hash * 4 + 2)) & 3))));
		hash++;
	}
	return (increment_offset(tet, di, map));
}
