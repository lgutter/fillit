/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 16:40:34 by aholster       #+#    #+#                */
/*   Updated: 2019/03/31 19:00:16 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	ft_putendl("error");
	exit(-1);
}

static unsigned short	di_exceptions(unsigned short di,\
						unsigned int *tet, short tetcount)
{
	short lc;
	short fc;
	short sc;
	short i;
	
	i = 0;
	sc = 0;
	lc = 0;
	fc = 0;
	while (i < tetcount)
	{
		if (tet[i] == 1164)
			lc++;
		if (tet[i] == 291)
			fc++;
		if (tet[i] == 325)
			sc++;
		i++;
	}
	if ((di < 8 && (di < lc || di < fc)) ||\
		(di % 2 == 1 && (sc * 4) > (di - 1) * (di - 1)) ||\
		(di >= 8 && (di + di < lc || di + di < fc)))
		return (di + 1);
	return (di);
}

static int				solve(unsigned int *tet, short curtet,\
						unsigned short *map, unsigned short di)
{
	if (tet[curtet] == 0)
	{
		print_result(tet, di);
	}
	if (calc_empty(map, di) < ((tet[26] - curtet) * 4))
	{
		return (0);
	}
	while (place_tet(&tet[curtet], map, di) == 1)
	{
		solve(tet, curtet + 1, map, di);
		if (remove_tet(&tet[curtet], map, di) == -1)
			return (0);
	}
	return (0);
}

void					map_control(unsigned int *tet, short tetcount)
{
	unsigned short	di;
	unsigned short	map[16];
	unsigned short	index;

	index = 0;
	di = smallest_map(tetcount);
	di = di_exceptions(di, tet, tetcount);
	while (index < 16)
	{
		map[index] = 0;
		index++;
	}
	while (solve(tet, 0, map, di) == 0 && di < 16)
	{
		di++;
	}
	ft_error();
}
