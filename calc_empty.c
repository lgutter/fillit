/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_empty.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/31 15:22:56 by lgutter       #+#    #+#                 */
/*   Updated: 2019/03/31 15:22:57 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static unsigned short	floodbit(unsigned short *map, unsigned short di,\
								unsigned short x, unsigned short y)
{
	unsigned short	chain;
	
	chain = 0;
	
	if (((map[y] >> x) & 1) == 1)
	{
		map[y] ^= 1 << x;
		chain++;
		if (y + 1 < di && ((map[y + 1] >> x) & 1) == 1)
			chain += floodbit(map, di, x, y + 1);
		if (x + 1 < di && ((map[y] >> (x + 1)) & 1) == 1)
			chain += floodbit(map, di, x + 1, y);
		if (x - 1 >= 0 && ((map[y] >> (x - 1)) & 1) == 1)
			chain += floodbit(map, di, x - 1, y);
		if (y - 1 >= 0 && ((map[y - 1] >> x) & 1) == 1)
			chain += floodbit(map, di, x, y - 1);
	}
	return (chain);
}

unsigned short			calc_empty(unsigned short *map, unsigned short di)
{
	unsigned short temp[16];
	unsigned short y;
	unsigned short x;
	unsigned short count;
	unsigned short chain;
	
	y = 0;
	count = 0;
	while (y < di)
	{
		temp[y] = ~map[y];
		y++;
	}
	y = 0;
	while (y < di)
	{
		x = 0;
		while (x < di)
		{
			if (((temp[y] >> x) & 1) == 1)
			{
				chain = floodbit(temp, di, x, y);
				if (chain >= 4)
					count += chain;
			}
			x++;
		}
		y++;
	}
	return (count);
}
