/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_tet.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 16:43:29 by lgutter       #+#    #+#                 */
/*   Updated: 2019/03/22 16:43:30 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_tet(unsigned int *tet)
{
	unsigned int	temp;
	short			check;
	short			count;

	count = 0;
	check = 12;
	shift_corner(tet);
	while (check >= 0)
	{
		temp = (*tet >> check) & 15;
		if ((temp < 6 && temp != 3) || temp == 8)
		{
			if ((temp + 1 == (*tet & 15)) || (temp + 1 == ((*tet >> 4) & 15))
				|| (temp + 1 == ((*tet >> 8) & 15)))
				count++;
			if ((temp + 4 == (*tet & 15)) || (temp + 4 == ((*tet >> 4) & 15))
				|| (temp + 4 == ((*tet >> 8) & 15)))
				count++;
		}
		check -= 4;
	}
	return (count / 3);
}
