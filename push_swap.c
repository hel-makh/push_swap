/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:36:32 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/17 20:06:34 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void	ft_push_to_stack_b(t_stacks *stacks, int nb)
{
	int	i;

	i =  ft_get_int_index(stacks->a, nb);
	while (stacks->a.stack[stacks->a.top] != nb)
	{
		if (i > stacks->a.top / 2)
			ft_ra(stacks);
		else
			ft_rra(stacks);
	}
	ft_pb(stacks);
}

void	ft_fill_stack_b(t_stacks *stacks, int stack_head)
{
	int	nb;
	int	comp;
	int	i;

	comp = ft_get_int_index(stacks->a, stack_head);
	i = comp - 1;
	if (i < 0)
		i = stacks->a.top - 1;
	while(stacks->a.stack[i] != stack_head)
	{
		// printf("i: %d\n", i);
		if (i < 0)
			i = stacks->a.top - 1;
		if (stacks->a.stack[i] == stack_head)
			break ;
		if (stacks->a.stack[i] > stacks->a.stack[comp])
			comp = i;
		else
		{
			nb = stacks->a.stack[i - 1];
			ft_push_to_stack_b(stacks, stacks->a.stack[i]);
			i = ft_get_int_index(stacks->a, nb) + 1;
		}
		i --;
	}
}

void	push_swap(t_stacks *stacks)
{
	int		stack_head;

	stack_head = ft_get_biggest_stack_head(stacks);
	// printf("stack_head: %d\n", stack_head);
	ft_fill_stack_b(stacks, stack_head);
	int i = stacks->a.top - 1;
	while (i >= 0)
		printf("a: %d\n", stacks->a.stack[i--]);
	printf("\n");
	i = stacks->b.top - 1;
	while (i >= 0)
		printf("b: %d\n", stacks->b.stack[i--]);
	ft_print_instructions(stacks->instructions);
}
