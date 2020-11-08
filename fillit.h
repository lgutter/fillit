/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/11 16:20:57 by aholster      #+#    #+#                 */
/*   Updated: 2019/03/25 15:37:55 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

/*
**	Masks for different parts of the int we store every tet and its info in.
*/
# define MASK2BIT		3
# define MASK4BIT		15
# define MASKBYTE		255
# define MASK2BYTE		65535
# define TET_SHAPE		65535

/*
**	Defines of number with a specific meaning
*/
# define MAX_TETS		26
# define TET_COUNT		MAX_TETS
# define MAP_SIZE		16
# define VERTICAL_BAR	1164
# define HORIZONTAL_BAR	291
# define SQUARE			325

/*
**	Contains the shape of a tet in the first 2 bytes (4 bits for the position of
**	each block of the tet), the x offset within the map in the third byte, and
**	the y offset within the map in the fourth and last byte.
*/
typedef unsigned int	t_tet_data;

int						parse_tet(t_tet_data *tet, char *buff);
void					fillit(int fd);
void					map_control(t_tet_data *tet, short tetcount);
int						place_tet(t_tet_data *tet, unsigned short *map,\
						unsigned short di);
unsigned short			smallest_map(short tetcount);
int						check_tet(t_tet_data *tet);
void					shift_corner(t_tet_data *tet);
void					ft_error(char *error);
unsigned short			calc_empty(unsigned short *map, unsigned short di);
int						remove_tet(t_tet_data *tet, unsigned short *map,\
unsigned short di);
int						increment_offset(t_tet_data *tet, unsigned short di);
void					print_result(t_tet_data *tet, unsigned short di);

#endif
