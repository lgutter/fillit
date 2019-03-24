/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   place_final.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 16:20:55 by lgutter       #+#    #+#                 */
/*   Updated: 2019/03/24 16:20:55 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	place_final(unsigned short tet, unsigned short *map)
{
	short			hash;
	unsigned char	y;
	unsigned char	x;
	
	hash = 0;
	while (hash < 4)
	{
		y = (((tet >> 16) & 255) + ((tet >> (hash * 4)) & 3));
		x = ((tet >> 24) + ((tet >> (hash * 4 + 2)) & 3));
		map[y] = map[y] | (1 << x);
		hash++;
	}
}
