/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   increment_offset.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 18:06:38 by lgutter       #+#    #+#                 */
/*   Updated: 2019/03/24 18:06:39 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	increment_offset(unsigned int *tet, unsigned short di, unsigned short *map)
{
	unsigned char *offx;
	unsigned char *offy;

	offx = (unsigned char *)(tet) + 2;
	offy = (unsigned char *)(tet) + 3;
	if (*offx < di && map[*offy] != 65535)
		*offx = *offx + 1;
	else if (*offy < di)
	{
		*offx = 0;
		*offy = *offy + 1;
	}
	else
	{
		*offx = 0;
		*offy = 0;
		return (-1);
	}
	return (1);
}
