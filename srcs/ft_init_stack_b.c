/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:25:49 by hel-makh          #+#    #+#             */
/*   Updated: 2022/02/05 18:59:03 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_swap_stack_a(t_stacks *stacks, int nb)
{
	while (stacks->a.stack[stacks->a.top - 1] != nb)
	{
		if (ft_get_int_index(stacks->a, nb) >= stacks->a.top / 2)
			ft_ra(stacks);
		else
			ft_rra(stacks);
	}
	ft_sa(stacks);
}

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

static void	ft_get_stack_sa_flags(
	t_stacks *stacks, int *flags, int *index, int *comp
	)
{
	int	i;
	int	j;

	i = ft_decrement_index(stacks->a, *index, 1);
	if (stacks->a.stack[i] < stacks->a.stack[*index]
		&& stacks->a.stack[i] > stacks->a.stack[*comp])
	{
		j = ft_decrement_index(stacks->a, i, 1);
		if (stacks->a.stack[j] == stacks->a.stack[*comp])
			flags[i] = 2;
		else
			flags[*index] = 2;
		*comp = *index;
		*index = i;
	}
	else
		*comp = *index;
}

static int	*ft_get_stack_flags(t_stacks *stacks, int stack_head)
{
	int	*flags;
	int	comp;
	int	i;

	flags = (int *)ft_calloc(stacks->a.top, sizeof(int));
	if (!flags)
		ft_quit_program(EXIT_FAILURE, stacks);
	comp = ft_get_int_index(stacks->a, stack_head);
	i = ft_decrement_index(stacks->a, comp, 1);
	while (stacks->a.stack[i] != stack_head)
	{
		if (stacks->a.stack[i] < stacks->a.stack[comp])
			flags[i] = 1;
		else
			ft_get_stack_sa_flags(stacks, flags, &i, &comp);
		i = ft_decrement_index(stacks->a, i, 1);
	}
	return (flags);
}

void	ft_init_stack_b(t_stacks *stacks)
{
	int	*stack;
	int	*flags;
	int	stack_head;
	int	i;

	stack = (int *)ft_calloc(stacks->a.top, sizeof(int));
	if (!stack)
		ft_quit_program(EXIT_FAILURE, stacks);
	stack = ft_memcpy(stack, stacks->a.stack, stacks->a.top * sizeof(int));
	stack_head = ft_get_biggest_stack_head(stacks);
	flags = ft_get_stack_flags(stacks, stack_head);
	i = stacks->a.top - 1;
	while (i >= 0)
	{
		if (flags[i] == 1)
			ft_push_to_stack_b(stacks, stack[i]);
		else if (flags[i] == 2)
			ft_swap_stack_a(stacks, stack[i]);
		i --;
	}
	stack = ft_free(stack);
	flags = ft_free(flags);
}
