/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_hash.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 14:10:41 by lgutter       #+#    #+#                 */
/*   Updated: 2019/03/24 14:10:42 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		check_hash(short hash, unsigned int tet,
				   unsigned short *map, unsigned short di)
{
	unsigned char y;
	unsigned char x;
	
	y = (((tet >> 16) & 255) + ((tet >> ((hash - 1) * 4)) & 3));
	x = ((tet >> 24) + ((tet >> ((hash - 1) * 4 + 2)) & 3));
	if (x <= di && y <= di && ((map[y] >> x) & 1) == 0)
			return (1);
	return (-1);
}
