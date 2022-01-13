/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:36:32 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/13 21:31:34 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void	ft_change_instruction(char **instruction, char **next, char *new)
{
	free(*instruction);
	*instruction = ft_strdup(new);
	ft_bzero(*next, ft_strlen(*next));
}

static void	ft_optimise_instructions(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (!ft_strncmp(arr[i], "sa", 2) && !ft_strncmp(arr[i + 1], "sb", 2))
			ft_change_instruction(&arr[i], &arr[i + 1], "ss");
		if (!ft_strncmp(arr[i], "ra", 2) && !ft_strncmp(arr[i + 1], "rb", 2))
			ft_change_instruction(&arr[i], &arr[i + 1], "rr");
		if (!ft_strncmp(arr[i], "rra", 3) && !ft_strncmp(arr[i + 1], "rrb", 3))
			ft_change_instruction(&arr[i], &arr[i + 1], "rrr");
		i ++;
	}
}

static void	ft_sort_a(t_stacks *stacks, int n, char **instructions)
{
	if (stacks->a.stack[n] == stacks->sorted.stack[n])
		return ;
	if (n == 0)
	{
		if (ft_get_int_index(stacks->a, stacks->sorted.stack[n])
			> stacks->a.top / 2)
			ft_ra(&stacks->a, &stacks->b, instructions);
		else
			ft_rra(&stacks->a, &stacks->b, instructions);
	}
	else
	{
		if (ft_get_int_index(stacks->a, stacks->sorted.stack[n])
			< stacks->a.top - 1)
			ft_pb(&stacks->a, &stacks->b, instructions);
		else
		{
			ft_sa(&stacks->a, &stacks->b, instructions);
			ft_pb(&stacks->a, &stacks->b, instructions);
		}
	}
}

static void	ft_sort_b(t_stacks *stacks, int n, char **instructions)
{
	if (n == 0)
		return ;
	if (ft_get_int_index(stacks->b, stacks->sorted.stack[n])
		== stacks->b.top - 1)
		ft_pa(&stacks->a, &stacks->b, instructions);
	else if (ft_get_int_index(stacks->b, stacks->sorted.stack[n])
		> stacks->b.top / 2)
		ft_rb(&stacks->a, &stacks->b, instructions);
	else if (ft_get_int_index(stacks->b, stacks->sorted.stack[n])
		<= stacks->b.top / 2)
		ft_rrb(&stacks->a, &stacks->b, instructions);
}

void	push_swap(t_stacks *stacks)
{
	int		n;
	int		i;
	char	*instructions;
	char	**arr;

	instructions = ft_strdup("");
	n = 0;
	while (n < stacks->sorted.top)
	{
		if (ft_get_int_index(stacks->a, stacks->sorted.stack[n]) != -1)
			ft_sort_a(stacks, n, &instructions);
		else if (ft_get_int_index(stacks->b, stacks->sorted.stack[n]) != -1)
			ft_sort_b(stacks, n, &instructions);
		if (stacks->a.stack[n] == stacks->sorted.stack[n])
			n ++;
	}
	arr = ft_split(instructions, '\n');
	instructions = ft_free(instructions);
	ft_optimise_instructions(arr);
	i = 0;
	while (arr[i])
		ft_putendl_fd(arr[i++], STDOUT_FILENO);
	arr = ft_free_2d(arr);
}
