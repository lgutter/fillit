/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/11 16:20:57 by aholster       #+#    #+#                */
/*   Updated: 2019/03/25 15:37:55 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define MASK2B	3
# define MASK4B	15
# define MASKBY	255

# include "libft.h"

void			map_control(unsigned int *tet, short tetcount);
int				place_tet(unsigned int *tet, unsigned short *map,\
unsigned short di);
unsigned short	smallest_map(short tetcount);
int				check_tet(unsigned int tet);
void			shift_corner(unsigned int *tet);
void			ft_error(void);
void			place_final(unsigned short tet, unsigned short *map);
int				check_hash(short hash, unsigned int tet,\
unsigned short *map, unsigned short di);
int				remove_tet(unsigned int *tet, unsigned short *map,\
unsigned short di);
int				increment_offset(unsigned int *tet, unsigned short di);
void			print_result(unsigned int *tet, unsigned short di);

#endif
