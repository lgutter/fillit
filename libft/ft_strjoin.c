/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 18:31:48 by aholster       #+#    #+#                */
/*   Updated: 2019/02/16 15:46:07 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	index;
	size_t	judex;
	char	*str;

	judex = 0;
	index = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[index] != '\0')
	{
		str[judex] = s1[index];
		judex++;
		index++;
	}
	index = 0;
	while (s2[index] != '\0')
	{
		str[judex] = s2[index];
		judex++;
		index++;
	}
	str[judex] = '\0';
	return (str);
}
