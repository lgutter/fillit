/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 15:58:35 by lgutter       #+#    #+#                 */
/*   Updated: 2019/03/25 15:58:37 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int fd;
	
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd >= 3)
			fillit(fd);
		else
			ft_error();
	}
	else
		ft_putendl("usage: ./fillit source_file");
	return (0);
}
