/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_tet.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 16:26:49 by lgutter       #+#    #+#                 */
/*   Updated: 2019/03/25 16:26:50 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		parse_tet(t_tet_data *tet, char *buff)
{
	short	i;
	short	hash;

	i = 0;
	hash = 0;
	if (ft_strlen(buff) < 20 || buff[19] != '\n')
		return (-1);
	while (i < 20)
	{
		while (buff[i] == '.')
			i++;
		if (buff[i] == '#' && hash < 4)
		{
			hash++;
			*tet = (*tet << 4) | (i - ((i + 1) / 5));
		}
		else if ((i + 1) % 5 != 0 || buff[i] != '\n')
			return (-1);
		i++;
	}
	if (hash != 4)
		return (-1);
	return (check_tet(tet));
}
