/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:52:51 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/13 20:52:54 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	*ft_free(void *ptr)
{
	free(ptr);
	return (NULL);
}

void	*ft_free_2d(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
	return (NULL);
}

void	*ft_free_3d(char ***ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		ft_free_2d(ptr[i++]);
	return (NULL);
}
