/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_segdefualt.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 17:57:56 by aholster       #+#    #+#                */
/*   Updated: 2019/02/01 20:55:46 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_segdefault(void)
{
	size_t	index;
	char	*str;

	index = 0;
	str = NULL;
	ft_putendl("WARNING: this is an intentional segfault by segdefualt");
	ft_putstr("Inevitably many shall fault the hands of those who felled");
	ft_putstr(" <this code>, but segdefualt merely performs the duty of its");
	ft_putendl(" office, to further fear it is redundant.");
	ft_putstr("those more sensible would place responsibility with those who");
	ft_putendl(" forced the hands of segdefualt.");
	ft_putendl("May imperial justice account in all balance.");
	while (str[index] != '\0')
	{
		index++;
	}
}
