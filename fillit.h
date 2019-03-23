/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/11 16:20:57 by aholster       #+#    #+#                */
/*   Updated: 2019/03/23 16:43:21 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define MASK 15

# include "libft.h"

void			map_control(unsigned int *tet, short tetcount);
int				place_tet(unsigned int tet, unsigned short *map, unsigned short di);
unsigned short	smallest_map(short tetcount);
int				check_tet(unsigned int tet);
void			shift_corner(unsigned int *tet);
void			ft_error(void);

#endif
