/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:25:49 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/21 20:25:41 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_is_sorted(t_stack st)
{
	int	i;
	int	j;
	int	nb;

	i = ft_get_min_index(st.stack, st.top);
	j = i;
	nb = st.stack[i];
	i = ft_decrement_index(st, i, 1);
	while (i != j)
	{
		if (st.stack[i] < nb)
			return (0);
		nb = st.stack[i];
		i = ft_decrement_index(st, i, 1);
	}
	return (1);
}

static void	ft_perform_swap(t_stacks *stacks, int stack_head)
{
	int	next_nb;
	int	index;

	if (ft_is_sorted(stacks->a))
		return ;
	next_nb = stacks->a.stack[ft_get_min_index(stacks->a.stack, stacks->a.top)];
	if (next_nb == stack_head)
		next_nb ++;
	while (ft_get_int_index(stacks->a, next_nb) == -1)
		next_nb ++;
	index = ft_increment_index(stacks->a, ft_get_int_index(stacks->a, next_nb), 1);
	index = stacks->a.stack[index];
	if (stacks->a.stack[stacks->a.top - 1] == next_nb)
	{
		ft_sa(stacks);
		return ;
	}
	if (next_nb > index)
		return ;
	if (ft_get_int_index(stacks->a, stack_head) > ft_get_int_index(stacks->a, next_nb))
		index = next_nb;
	while (stacks->a.stack[stacks->a.top - 1] != index)
	{
		if (ft_get_int_index(stacks->a, index) > stacks->a.top / 2)
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

void	ft_init_stack_b(t_stacks *stacks)
{
	int	stack_head;
	int	comp;
	int	nb;
	int	i;

	stack_head = ft_get_biggest_stack_head(stacks);
	if (stacks->a.top <= 3)
		ft_perform_swap(stacks, stack_head);
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
