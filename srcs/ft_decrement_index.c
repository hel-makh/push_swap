/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decrement_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:13:08 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/18 12:18:13 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_decrement_index(t_stack st, int index, int dec_by)
{
	int	i;

	i = 0;
	while (i < dec_by)
	{
		if (index > 0)
			index --;
		else
			index = st.top - 1;
		i ++;
	}
	return (index);
}
