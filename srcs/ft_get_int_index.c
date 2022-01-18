/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_int_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:37:56 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/18 13:03:44 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_get_int_index(t_stack st, int nb)
{
	int	i;

	i = 0;
	while (i < st.top)
	{
		if (st.stack[i] == nb)
			return (i);
		i ++;
	}
	return (-1);
}
