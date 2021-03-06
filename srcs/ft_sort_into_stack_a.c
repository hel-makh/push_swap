/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_into_stack_a.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:36:14 by hel-makh          #+#    #+#             */
/*   Updated: 2022/02/05 18:59:55 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_get_int_next_to(t_stack st, int nb)
{
	int	i;
	int	j;

	i = 0;
	while (i < st.top)
	{
		j = ft_decrement_index(st, i, 1);
		if (st.stack[i] < nb
			&& st.stack[j] > nb)
			return (st.stack[j]);
		i ++;
	}
	return (ft_get_min(st));
}

static int	ft_get_inst_nb_to_top(
	t_stacks *stacks, int nb, int next_nb, int *path
	)
{
	int	index;
	int	next_nb_index;
	int	inst_nb[3];

	index = ft_get_int_index(stacks->b, nb);
	next_nb_index = ft_get_int_index(stacks->a, next_nb);
	if (index >= stacks->b.top / 2)
		inst_nb[0] = stacks->b.top - 1 - index;
	else
		inst_nb[0] = index + 1;
	if (next_nb_index >= stacks->a.top / 2)
		inst_nb[0] += stacks->a.top - 1 - next_nb_index;
	else
		inst_nb[0] += next_nb_index + 1;
	if (index + 1 > next_nb_index + 1)
		inst_nb[1] = index + 1;
	else
		inst_nb[1] = next_nb_index + 1;
	if (stacks->b.top - 1 - index > stacks->a.top - 1 - next_nb_index)
		inst_nb[2] = stacks->b.top - 1 - index;
	else
		inst_nb[2] = stacks->a.top - 1 - next_nb_index;
	if (path)
		*path = ft_get_min_index(inst_nb, 3);
	return (inst_nb[ft_get_min_index(inst_nb, 3)]);
}

static int	ft_li_nb_to_stack_a(t_stacks *stacks)
{
	int	*count;
	int	comp;
	int	next_nb;
	int	i;

	count = (int *)ft_calloc(stacks->b.top, sizeof(int));
	if (!count)
		ft_quit_program(EXIT_FAILURE, stacks);
	comp = 0;
	i = 0;
	while (i < stacks->b.top)
	{
		next_nb = ft_get_int_next_to(stacks->a, stacks->b.stack[i]);
		count[i] = ft_get_inst_nb_to_top(
				stacks, stacks->b.stack[i], next_nb, NULL
				);
		if (count[i] <= count[comp])
			comp = i;
		i ++;
	}
	count = ft_free(count);
	return (stacks->b.stack[comp]);
}

static void	ft_push_to_stack_a(t_stacks *stacks, int nb, int next_nb, int path)
{
	if (path == 1)
		while (stacks->a.stack[stacks->a.top - 1] != next_nb
			&& stacks->b.stack[stacks->b.top - 1] != nb)
			ft_rrr(stacks);
	else if (path == 2)
		while (stacks->a.stack[stacks->a.top - 1] != next_nb
			&& stacks->b.stack[stacks->b.top - 1] != nb)
			ft_rr(stacks);
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
	int	next_nb;
	int	path;
	int	min;

	while (stacks->b.top)
	{
		nb = ft_li_nb_to_stack_a(stacks);
		next_nb = ft_get_int_next_to(stacks->a, nb);
		ft_get_inst_nb_to_top(stacks, nb, next_nb, &path);
		ft_push_to_stack_a(stacks, nb, next_nb, path);
	}
	min = ft_get_min(stacks->a);
	while (stacks->a.stack[stacks->a.top - 1] != min)
	{
		if (ft_get_int_index(stacks->a, min) >= stacks->a.top / 2)
			ft_ra(stacks);
		else
			ft_rra(stacks);
	}
}
