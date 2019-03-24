/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   smallest_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 16:26:43 by lgutter        #+#    #+#                */
/*   Updated: 2019/03/24 18:42:22 by aholster      ########   odam.nl         */
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
			return (6);
		if (tetcount < 7)
			return (5);
		if (tetcount > 9)
			return (7);
	}
	if (tetcount < 17)
		return (8);
	if (tetcount < 21)
		return (9);
	if (tetcount < 26)
		return (10);
	return (11);
}
