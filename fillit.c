/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 16:12:43 by lgutter       #+#    #+#                 */
/*   Updated: 2019/03/25 16:12:44 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit(int fd)
{
	unsigned int	tet[27];
	short			tc;
	char			buffer[20];
	ssize_t			ret;
	
	tc = 0;
	ret = read(fd, buffer, 20);
	tet[tc] = 0;
	while (tc != 26 && ret != 0)
	{
		if (read_tet(&tet[tc], buffer) != 1 || check_tet(&tet[tc]) != 1)
			ft_error();
		tc++;
		if (read(fd, buffer, 1) == 1)
		{
			if (buffer[0] != '\n')
				ft_error();
			ret = read(fd, buffer, 20);
			if (ret != 20)
				ft_error();
		}
		else ret = 0;
		tet[tc] = 0;
	}
	close (fd);
	tet[26] = tc;
	map_control(&tet[0], tc);
}
