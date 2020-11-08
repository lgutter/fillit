/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shift_corner.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 16:41:44 by lgutter       #+#    #+#                 */
/*   Updated: 2019/03/22 16:43:01 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	This function shifts the tet to the top left corner of the virtual grid it
**	is stored in. We start by comparing the x position of the first 3 blocks.
**	we can get the x position by using modulo 4, as the positions are not
**	coordinates but positions as if the 4 rows were one long row. for example:
**	with x:2 y: 1 , the position is (4 * y) + x = 6 (coordinates start at 0)
**	the fourth block can not possibly be the leftmost block, so we don't need
**	to check it. We set the variable "smallest" to the value of the left-most
**	block, modulo 4. the modulo 4 automatically shifts it to the top row.
**	to make sure we don't shift the block to high (if the 2nd or 3rd was the
**	left-most block, the first block will now be in row -1), we set our "temp"
**	variable to the value of the first block after rounding it down to the
**	nearest multiple of 4 by abusing integer rounding.
**	now we add the "temp" variable (now holding the minimum y) to the "smallest"
**	variable (holding the minimum x) so we get the amount of positions every
**	block needs to be shifted. Then all we need to do is shift every block and
**	and them to the "temp" variable, after which we overwrite the original tet
**	with our shifted version in "temp".
*/

/*
**	Defines for the different blocks
*/
#define FIRST_B		12
#define SECOND_B	8
#define THIRD_B		4

/*
**	defines to clarify calculating with rows
*/
#define ROW_WIDTH	4
#define ROW_COUNT	4

void	shift_corner(t_tet_data *tet)
{
	unsigned short smallest;
	unsigned short temp;

	smallest = (*tet >> FIRST_B) % ROW_WIDTH;
	if (smallest > ((*tet >> SECOND_B) & MASK4BIT) % ROW_WIDTH)
		smallest = ((*tet >> SECOND_B) & MASK4BIT) % ROW_WIDTH;
	if (smallest > ((*tet >> THIRD_B) & MASK4BIT) % ROW_WIDTH)
		smallest = ((*tet >> THIRD_B) & MASK4BIT) % ROW_WIDTH;
	temp = ((*tet >> FIRST_B) / ROW_COUNT) * ROW_COUNT;
	smallest += temp;
	temp = ((*tet >> FIRST_B) - smallest) << FIRST_B;
	temp = ((((*tet >> SECOND_B) & MASK4BIT) - smallest) << SECOND_B) | temp;
	temp = ((((*tet >> THIRD_B) & MASK4BIT) - smallest) << THIRD_B) | temp;
	temp = ((*tet & MASK4BIT) - smallest) | temp;
	*tet = temp;
}
