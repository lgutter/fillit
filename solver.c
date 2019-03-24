/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 16:40:34 by aholster       #+#    #+#                */
/*   Updated: 2019/03/24 18:37:27 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	ft_putendl("error");
	exit(-1);
}

void	print_result(unsigned int *tet, unsigned short di)
{
	char			**arr;
	unsigned int	index;

	(void)tet;
	index = 0;
	arr = (char **)malloc(sizeof(char *) * di);
	if (arr == NULL)
		ft_error();
	while (index < di)
	{
		arr[index] = (char *)malloc(sizeof(char) * di + 1);
		if (arr[index] == NULL)
			ft_error();
		index++;
	}
	
	exit (1);
}

int		solve(unsigned int *tet, short curtet, unsigned short *map,\
unsigned short di)
{
	if (tet[curtet] == 0)
	{
		print_result(tet, di);
	}
	while (place_tet(&tet[curtet], map, di) == 1)
	{
		solve(tet, curtet + 1, map, di);
		if (remove_tet(&tet[curtet], map, di) == -1)
			return (0);
	}
	return (0);
}

void	map_control(unsigned int *tet, short tetcount)
{
	unsigned short	di;
	unsigned short	map[16];
	unsigned short	index;

	index = 0;
	di = smallest_map(tetcount);\
//	map = (unsigned short *)malloc(sizeof(unsigned short *) * 16);
//	if (map == NULL)
//		ft_error();
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
