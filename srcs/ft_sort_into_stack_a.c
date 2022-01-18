/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_into_stack_a.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:36:14 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/18 19:45:19 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_get_int_next_to(t_stack st, int nb)
{
	int	i;
	int	j;
	int	smallest;

	i = 0;
	while (i < st.top)
	{
		j = ft_decrement_index(st, i, 1);
		if(st.stack[i] < nb
			&& st.stack[j] > nb)
			return (st.stack[j]);
		i ++;
	}
	smallest = st.stack[0];
	i = 1;
	while (i < st.top)
	{
		if (st.stack[i] < smallest)
			smallest = st.stack[i];
		i ++;
	}
	return (smallest);
}

static int	ft_get_inst_nb_to_top(t_stack st, int nb)
{
	int	inst_nb;
	int	index;

	index = ft_get_int_index(st, nb);
	if (index >= st.top / 2)
		inst_nb = st.top - 1 - index;
	else
		inst_nb = index + 1;
	return (inst_nb);
}

static int	ft_get_li_int(t_stacks *stacks)
{
	int	*count;
	int	comp;
	int	nb;
	int	i;

	count = (int *)ft_calloc(stacks->b.top, sizeof(int));
	comp = -1;
	i = 0;
	while (i < stacks->b.top)
	{
		count[i] += ft_get_inst_nb_to_top(stacks->b, stacks->b.stack[i]);
		nb = ft_get_int_next_to(stacks->a, stacks->b.stack[i]);
		count[i] += ft_get_inst_nb_to_top(stacks->a, nb);
		if (comp == -1)
			comp = i;
		if (count[i] < count[comp])
			comp = i;
		i ++;
	}
	count = ft_free(count);
	return (stacks->b.stack[comp]);
}

static void	ft_push_to_stack_a(t_stacks *stacks, int nb)
{
	int	next_nb;

	next_nb = ft_get_int_next_to(stacks->a, nb);
	while (stacks->a.stack[stacks->a.top - 1] != next_nb)
	{
		if (ft_get_int_index(stacks->a, next_nb) >= stacks->a.top / 2)
			ft_ra(stacks);
		else
			ft_rra(stacks);
	}
	while (stacks->b.stack[stacks->b.top - 1] != nb)
	{
		if (ft_get_int_index(stacks->b, nb) >= stacks->b.top / 2)
			ft_rb(stacks);
		else
			ft_rrb(stacks);
	}
	ft_pa(stacks);
}

void	ft_sort_into_stack_a(t_stacks *stacks)
{
	int	nb;

	while (stacks->b.top)
	{
		nb = ft_get_li_int(stacks);
		ft_push_to_stack_a(stacks, nb);
	}
	while (stacks->a.stack[0] != stacks->sorted.stack[0])
	{
		if (ft_get_int_index(stacks->a, stacks->sorted.stack[0])
			>= stacks->a.top / 2)
			ft_ra(stacks);
		else
			ft_rra(stacks);
	}
}
