/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 16:40:34 by aholster      #+#    #+#                 */
/*   Updated: 2019/03/31 19:05:41 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	this tiny function is 90% of our speed. essentially, we check if we've
**	placed a tetromino with the same shape (for example a square) before,
**	by iterating over the already placed tets and comparing the value of the
**	first 2 bytes in the t_tet_data, which contains the shape.
**	if a value matches, we simply duplicate that previous tet, skipping any
**	invalid placements before that position.
*/

static t_tet_data		duplicate_shortcut(t_tet_data *tet,\
						short curtet, t_tet_data current)
{
	while (curtet > 0)
	{
		if (current == (tet[curtet - 1] & MASK2BYTE))
			return (tet[curtet - 1]);
		curtet--;
	}
	return (current);
}

/*
**	Check the count of 3 specific tetromino shapes. If we have a certain amount
**	of these, we should start 1 map size larger to save time.
**	the unreadable if statement contains the following rules:
**	-	if the size is less then 8, and we have more bars than size, increase.
**	-	if size is an odd number, and our squares will take up more space than
**		the area we would have if size was 1 smaller, increase.
**	-	if size is larger than 7, (so 2 bars will fit next to each other), and
**		we have more bars than (size * 2), increase.
*/

static unsigned short	size_exceptions(unsigned short size,\
						t_tet_data *tet, short tetcount)
{
	short vertical_bars;
	short horizontal_bars;
	short squares;
	short i;

	i = 0;
	squares = 0;
	vertical_bars = 0;
	horizontal_bars = 0;
	while (i < tetcount)
	{
		if (tet[i] == VERTICAL_BAR)
			vertical_bars++;
		if (tet[i] == HORIZONTAL_BAR)
			horizontal_bars++;
		if (tet[i] == SQUARE)
			squares++;
		i++;
	}
	if ((size < 8 && (size < vertical_bars || size < horizontal_bars)) ||\
		(size % 2 == 1 && (squares * 4) > (size - 1) * (size - 1)) ||\
		(size >= 8 && (size * 2 < vertical_bars || size * 2 < horizontal_bars)))
		return (size + 1);
	return (size);
}

/*
**	The main recursive solve function. first we have a stop condition: when our
**	current count of tets is >= tet_count, we print result and exit.
**	then we calculate if there is still enough usable space, otherwise we return
**	then we check if we placed this shape before, if so, skip to last position.
**	then we place the tet in the first available location, and call ourselves
**	for the next tet.
**	when solve returns, we try to move the tet the a next possible position.
**	if there is no next possible position, we return.
*/

static int				solve(t_tet_data *tet, short curtet,\
						unsigned short *map, unsigned short di)
{
	if (curtet >= (short)tet[TET_COUNT])
	{
		print_result(tet, di);
	}
	if (calc_empty(map, di) < ((tet[TET_COUNT] - curtet) * 4))
	{
		return (0);
	}
	tet[curtet] = duplicate_shortcut(tet, curtet, tet[curtet]);
	while (place_tet(&tet[curtet], map, di) == 1)
	{
		solve(tet, curtet + 1, map, di);
		if (remove_tet(&tet[curtet], map, di) == -1)
			return (0);
	}
	return (0);
}

/*
**	this table contains the pre-calculated smallest map size based on the amount
**	of tetrominoes. The index is the amount of tetrominoes,
**	and the value is the size of the square map. so 8 tetrominoes needs a
**	minimal size of 6x6. position 0 is simply to avoid needing to translate a
**	count to an index, since that adds unneeded obscurity.
*/
static const unsigned short g_smallest_size[27] = {
	[0] = 0,
	[1] = 2,
	[2] = 3,
	[3] = 4,
	[4] = 4,
	[5] = 5,
	[6] = 5,
	[7] = 6,
	[8] = 6,
	[9] = 6,
	[10] = 7,
	[11] = 7,
	[12] = 7,
	[13] = 8,
	[14] = 8,
	[15] = 8,
	[16] = 8,
	[17] = 9,
	[18] = 9,
	[19] = 9,
	[20] = 9,
	[21] = 10,
	[22] = 10,
	[23] = 10,
	[24] = 10,
	[25] = 10,
	[26] = 11,
};

/*
**	starts with the smallest possible map that could fit the current amount of
**	tetrominoes, and keeps trying to solve with a larger map size until we hit
**	the maximum size of 16.
*/

void					map_control(t_tet_data *tet, short tetcount)
{
	unsigned short	di;
	unsigned short	map[MAP_SIZE + 2];

	ft_memset(map, 0, sizeof(map));
	di = size_exceptions(g_smallest_size[tetcount], tet, tetcount);
	while (solve(tet, 0, map, di) == 0 && di < MAP_SIZE)
	{
		di++;
	}
	ft_error("Could not solve within 16x16 map!");
}
