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

void	shift_corner(unsigned int *tet)
{
	unsigned short smallest;
	unsigned short temp;

	smallest = (*tet >> 12) % 4;
	if (smallest > ((*tet >> 8) & 15) % 4)
		smallest = ((*tet >> 8) & 15) % 4;
	if (smallest > ((*tet >> 4) & 15) % 4)
		smallest = ((*tet >> 4) & 15) % 4;
	temp = ((*tet >> 12) / 4) * 4;
	smallest += temp;
	temp = ((*tet >> 12) - smallest) << 12;
	temp = ((((*tet >> 8) & 15) - smallest) << 8) | temp;
	temp = ((((*tet >> 4) & 15) - smallest) << 4) | temp;
	temp = ((*tet & 15) - smallest) | temp;
	*tet = temp;
}
