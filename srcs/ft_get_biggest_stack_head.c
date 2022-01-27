/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_biggest_stack_head.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:33:04 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/27 18:47:04 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_compare_ints(t_stacks *stacks, int *count, int i)
{
	int	comp;
	int	j;
	int	k;

	comp = i;
	j = ft_decrement_index(stacks->a, i, 1);
	while (j != i)
	{
		if (stacks->a.stack[j] > stacks->a.stack[comp])
		{
			k = ft_decrement_index(stacks->a, j, 1);
			if (stacks->a.stack[k] < stacks->a.stack[j]
				&& stacks->a.stack[k] > stacks->a.stack[comp])
				count[i] += 1;
			count[i] += 1;
			comp = j;
		}
		j = ft_decrement_index(stacks->a, j, 1);
	}
}

int	ft_get_biggest_stack_head(t_stacks *stacks)
{
	int	i;
	int	head;
	int	*count;

	count = (int *)ft_calloc(stacks->a.top, sizeof(int));
	i = stacks->a.top - 1;
	head = stacks->a.stack[i];
	while (i >= 0)
	{
		ft_compare_ints(stacks, count, i);
		if (count[i] > count[ft_get_int_index(stacks->a, head)]
			|| (count[i] == count[ft_get_int_index(stacks->a, head)]
				&& stacks->a.stack[i] > head))
			head = stacks->a.stack[i];
		i --;
	}
	count = ft_free(count);
	return (head);
}
