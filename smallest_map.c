/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   smallest_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lgutter <lgutter@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 16:26:43 by lgutter       #+#    #+#                 */
/*   Updated: 2019/03/22 16:47:27 by lgutter       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

unsigned short	smallest_map(short tetcount)
{
	if (tetcount < 5)
	{
		if (tetcount < 4)
			return (tetcount + 1);
		return (4);
	}
	if (tetcount < 13)
	{
		if (tetcount > 6 && tetcount < 10)
			return(6);
		if (tetcount < 7)
			return(5);
		if (tetcount > 9)
			return(7);
	}
	if (tetcount < 17)
		return(8);
	if (tetcount < 21)
		return(9);
	if (tetcount < 26)
		return(10);
	return(11);
}
