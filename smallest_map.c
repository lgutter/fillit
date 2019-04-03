/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   smallest_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 16:26:43 by lgutter        #+#    #+#                */
/*   Updated: 2019/04/01 15:49:33 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

unsigned short	smallest_map(short tetcount)
{
	if (tetcount < 13)
	{
		if (tetcount < 5)
			return ((tetcount < 4) ? tetcount + 1 : 4);
		if (tetcount < 7)
			return (5);
		return ((tetcount < 10) ? 6 : 7);
	}
	if (tetcount < 21)
		return ((tetcount < 17) ? 8 : 9);
	return ((tetcount < 26) ? 10 : 11);
}
