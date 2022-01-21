/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:49:52 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/21 13:50:03 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_get_min(t_stack st)
{
	int	min;
	int	i;

	min = st.stack[0];
	i = 0;
	while (i < st.top)
	{
		if (st.stack[i] < min)
			min = st.stack[i];
		i ++;
	}
	return (min);
}
