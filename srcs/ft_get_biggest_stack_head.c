/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_biggest_stack_head.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:33:04 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/17 19:22:07 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_compare_ints(t_stacks *stacks, int *count, int i)
{
	int	comp;
	int	j;

	comp = i;
	j = i - 1;
	while (j != i)
	{
		if (j < 0)
			j = stacks->a.top - 1;
		if (j == i)
			break ;
		if (stacks->a.stack[j] > stacks->a.stack[comp])
		{
			count[i] += 1;
			comp = j;
		}
		j --;
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
		if (i < stacks->a.top && count[i] > count[i + 1])
			head = stacks->a.stack[i];
		i --;
	}
	// int j = 0;
	// while (j < stacks->a.top)
	// {
	// 	printf("count of %d: %d\n", stacks->a.stack[j], count[j]);
	// 	j ++;
	// }
	count = ft_free(count);
	return (head);
}
