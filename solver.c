/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 16:40:34 by aholster       #+#    #+#                */
/*   Updated: 2019/03/23 17:32:45 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	ft_putendl("error");
	exit (-1);
}

void	print_result(unsigned int *tet, unsigned short *map, unsigned short di)
{
	(void)tet;
	(void)map;
	(void)di;

	exit (1);
}

int		solve(unsigned int *tet, short curtet, unsigned short *map, unsigned short di)
{
//	int	ret;

	if (tet[curtet] == 0)
	{
		print_result(tet, map, di);
//		return (1);
	}
	while (place_tet(tet[curtet], map, di) == 1)
	{
		/*ret = */solve(tet, curtet + 1, map, di);
//		if (ret == 1)
//			return (1);
	}
	return (0);
}

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
	while (solve(tet, 0, map, di) == 0 && di < 16)
	{
		di++;
	}
}
