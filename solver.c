/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 16:40:34 by aholster       #+#    #+#                */
/*   Updated: 2019/03/22 17:10:56 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	map_control(unsigned int *tet, short tetcount)
{
	unsigned short	di;
	unsigned short	*map;
	unsigned short	index;

	index = 0;
	di = smallest_map(tetcount);
	map = (unsigned short *)malloc(sizeof(unsigned short *) * 16);
	if (map == NULL)
		ft_error();
	while (index < 16)
	{
		map[index] = 0;
		index++;
	}
	while (solve(tet, 0, map, di) == 0)
	{
		di++;
	}
}

int	solve(unsigned int *tet, short curtet, unsigned short *map, unsigned short di)
{
	int	ret;

	if (tet[curtet] == 0)
		return (42);
	while (tet_place(tet[curtet], map, di) == 1)
	{
		ret = solve(tet, curtet + 1, map, di);
		if (ret == 42)
			print_result(tet, map, di);
	}
	return (0);
}
