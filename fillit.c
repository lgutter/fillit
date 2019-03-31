/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 16:12:43 by lgutter       #+#    #+#                 */
/*   Updated: 2019/03/31 19:13:00 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit(int fd)
{
	unsigned int	tet[27];
	char			buff[20];
	ssize_t			ret;

	tet[26] = 0;
	ret = read(fd, buff, 20);
	while (tet[26] != 26 && ret != 0)
	{
		tet[tet[26]] = 0;
		if (read_tet(&tet[tet[26]], buff) != 1 || check_tet(&tet[tet[26]]) != 1)
			ft_error();
		tet[26]++;
		if (read(fd, buff, 1) == 1)
		{
			if (buff[0] != '\n')
				ft_error();
			ret = read(fd, buff, 20);
			if (ret != 20)
				ft_error();
		}
		else
			ret = 0;
	}
	close(fd);
	map_control(&tet[0], tet[26]);
}
