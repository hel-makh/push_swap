/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:25:49 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/18 15:16:00 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_push_to_stack_b(t_stacks *stacks, int nb)
{
	while (stacks->a.stack[stacks->a.top - 1] != nb)
	{
		if (ft_get_int_index(stacks->a, nb) >= stacks->a.top / 2)
			ft_ra(stacks);
		else
			ft_rra(stacks);
	}
	ft_pb(stacks);
}

void	ft_init_stack_b(t_stacks *stacks)
{
	int	stack_head;
	int	comp;
	int	nb;
	int	i;

	stack_head = ft_get_biggest_stack_head(stacks);
	comp = ft_get_int_index(stacks->a, stack_head);
	i = ft_decrement_index(stacks->a, comp, 1);
	while (stacks->a.stack[i] != stack_head)
	{
		if (stacks->a.stack[i] <= stacks->a.stack[comp])
		{
			nb = stacks->a.stack[i - 1];
			comp = stacks->a.stack[comp];
			ft_push_to_stack_b(stacks, stacks->a.stack[i]);
			i = ft_get_int_index(stacks->a, nb) + 1;
			comp = ft_get_int_index(stacks->a, comp);
		}
		else
			comp = i;
		i = ft_decrement_index(stacks->a, i, 1);
	}
}
