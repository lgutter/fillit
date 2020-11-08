/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_result.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 15:37:06 by aholster      #+#    #+#                 */
/*   Updated: 2019/04/01 15:00:02 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_converttet(t_tet_data tet, unsigned short index,\
			char arr[16][16])
{
	unsigned short	offy;
	unsigned short	offx;
	unsigned char	offset;

	offy = (tet >> 16) & MASKBYTE;
	offx = (tet >> 24);
	offset = 0;
	while (offset <= 12)
	{
		arr[offx + ((tet >> (offset + 2)) & MASK2BIT)]\
		[offy + ((tet >> offset) & MASK2BIT)] = 'A' + index;
		offset += 4;
	}
}

static void	ft_initsquare(unsigned short di, char arr[16][16])
{
	unsigned short	index;
	unsigned short	sudex;

	index = 0;
	while (index < di)
	{
		sudex = 0;
		while (sudex < di)
		{
			arr[index][sudex] = '.';
			sudex++;
		}
		arr[index][sudex] = '\0';
		index++;
	}
}

void		print_result(t_tet_data *tet, unsigned short di)
{
	char			arr[16][16];
	unsigned short	index;

	index = 0;
	ft_initsquare(di, arr);
	while (index < tet[26])
	{
		ft_converttet(tet[index], index, arr);
		index++;
	}
	index = 0;
	while (index < di)
	{
		ft_putendl(arr[index]);
		index++;
	}
	exit(1);
}
