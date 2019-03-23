/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 15:42:31 by aholster       #+#    #+#                */
/*   Updated: 2019/02/16 17:59:13 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				index;
	unsigned char		*input;
	unsigned const char *output;

	index = 0;
	input = (unsigned char *)dst;
	output = (unsigned char const *)src;
	while (index < n)
	{
		input[index] = output[index];
		index++;
	}
	return (dst);
}
