/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_increment_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:13:08 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/18 12:17:02 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_increment_index(t_stack st, int index, int inc_by)
{
	int	i;

	i = 0;
	while (i < inc_by)
	{
		if (index < st.top - 1)
			index ++;
		else
			index = 0;
		i ++;
	}
	return (index);
}
