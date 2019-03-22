/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   place_tet.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 16:51:36 by lgutter       #+#    #+#                 */
/*   Updated: 2019/03/22 17:34:14 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		place_tet(unsigned int tet, unsigned short *map, unsigned short di)
{
	unsigned short offx;
	unsigned short offy;

	offx = (tet >> 20);
	offy = ((tet >> 16) & 15);
	while (((map[offy + ((tet >> 12) & 3)] >> (offx + ((tet >> 14)) & 3)) & 1)
			!= 0 ||
		   ((map[offy + ((tet >> 8) & 3)] >> (offx + ((tet >> 10)) & 3)) & 1)
			!= 0 ||
		   ((map[offy + ((tet >> 4) & 3)] >> (offx + ((tet >> 6)) & 3)) & 1)
			!= 0 ||
		   ((map[offy + (tet & 3)] >> (offx + ((tet >> 2)) & 3)) & 1) != 0)
	{
		if (offx < di)
			offx++;
		else if (offy < di)
		{
			offx = 0;
			offy++;
		}
		else
			return (-1);
	}
	
}
