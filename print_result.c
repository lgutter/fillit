/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_result.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 15:37:06 by aholster       #+#    #+#                */
/*   Updated: 2019/03/25 15:55:30 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_converttet(unsigned int tet, unsigned int index, char **arr)
{
	unsigned short	offy;
	unsigned short	offx;
	unsigned char	offset;

	offy = (tet >> 16) & MASKBY;
	offx = (tet >> 24);
	offset = 0;
	while (offset < 12)
	{
		arr[offy + ((tet >> offset) & MASK2B)]\
		[offx + ((tet >> (offset + 2)) & MASK2B)] = 'A' + index;
		offset += 4;
	}
}

void		print_result(unsigned int *tet, unsigned short di)
{
	char			**arr;
	unsigned int	index;

	index = 0;
	arr = ft_textangle(di, di, '.');
	if (arr == NULL)
		ft_error();
	while (tet[index] != 0)
	{
		ft_converttet(tet[index], index, arr);
		index++;
	}
	ft_putstrarr(arr);
	exit(1);
}
