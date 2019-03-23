/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstleng.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 17:32:55 by aholster       #+#    #+#                */
/*   Updated: 2019/02/01 21:29:22 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_lstleng(t_list *lst)
{
	unsigned int	index;

	index = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		index++;
	}
	return (index);
}
