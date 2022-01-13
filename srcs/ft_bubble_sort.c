/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:39:18 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/13 17:45:26 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	ft_sort(t_stack st)
{
	int		i;
	int		j;
	int		swap;
	t_stack	sorted;

	sorted.stack = (int *) malloc (st.top * sizeof(int));
	sorted.top = st.top;
	ft_memcpy(sorted.stack, st.stack, st.top * sizeof(int));
	i = -1;
	while (++i < st.top)
	{
		j = 0;
		while (j < st.top - 1)
		{
			if (sorted.stack[j] < sorted.stack[j + 1])
			{
				swap = sorted.stack[j];
				sorted.stack[j] = sorted.stack[j + 1];
				sorted.stack[j + 1] = swap;
			}
			j ++;
		}
	}
	return (sorted);
}
