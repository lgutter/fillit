/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 16:12:43 by lgutter       #+#    #+#                 */
/*   Updated: 2019/04/01 15:13:00 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(char *error)
{
	ft_putstr_fd("fillit: ", STDERR_FILENO);
	ft_putendl_fd(error, STDERR_FILENO);
	exit(-1);
}

void	fillit(int fd)
{
	t_tet_data	tet[MAX_TETS + 1];
	char		buff[20];
	ssize_t		ret;

	tet[TET_COUNT] = 0;
	ret = read(fd, buff, 20);
	while (true)
	{
		tet[tet[TET_COUNT]] = 0;
		if (parse_tet(&tet[tet[TET_COUNT]], buff) != 1)
			ft_error("parsing error!");
		tet[TET_COUNT]++;
		if (read(fd, buff, 1) == 1)
		{
			if (buff[0] != '\n')
				ft_error("tetromino definitions should be seperated by '\\n'");
			ret = read(fd, buff, 20);
			if (ret != 20 || tet[TET_COUNT] >= MAX_TETS)
				ft_error(ret == 20 ? "too many tetrominos!" : "parsing error!");
		}
		else
			break ;
	}
	close(fd);
	map_control(&tet[0], tet[TET_COUNT]);
}
