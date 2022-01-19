/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:51:56 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/19 21:15:14 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_change_instruction(char **instruction, char *next, char *new)
{
	if (!*instruction || !next)
		return ;
	free(*instruction);
	*instruction = ft_strdup(new);
	ft_bzero(next, ft_strlen(next));
}

static int	ft_inst_matches(char *inst1, char *inst2, char *comp1, char *comp2)
{
	if (!inst1 || !inst2)
		return (0);
	if (!ft_memcmp(inst1, comp1, ft_strlen(comp1))
		&& !ft_memcmp(inst2, comp2, ft_strlen(comp2)))
		return (1);
	else if (!ft_memcmp(inst1, comp2, ft_strlen(comp2))
		&& !ft_memcmp(inst2, comp1, ft_strlen(comp1)))
		return (1);
	return (0);
}

static char	*ft_get_next_inst(char **arr)
{
	char	*first_inst;
	int		i;

	first_inst = arr[0];
	i = 0;
	while (arr[i]
		&& (!*arr[i] || (ft_strlen(arr[i]) == ft_strlen(first_inst)
				&& !ft_memcmp(arr[i], first_inst, ft_strlen(first_inst)))))
		i ++;
	if (arr[i] && ft_strlen(arr[i]) == ft_strlen(first_inst)
		&& !ft_memcmp(arr[i], first_inst, ft_strlen(first_inst) - 1)
		&& arr[i][ft_strlen(arr[i]) - 1]
		!= first_inst[ft_strlen(first_inst) - 1])
		return (arr[i]);
	return (NULL);
}

static void	ft_optimise_instructions(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (ft_inst_matches(arr[i], arr[i + 1], "sa", "sb"))
			ft_change_instruction(&arr[i], arr[i + 1], "ss");
		if (!ft_memcmp(arr[i], "ra", 2) || !ft_memcmp(arr[i], "rb", 2))
			ft_change_instruction(&arr[i], ft_get_next_inst(&arr[i]), "rr");
		if (!ft_memcmp(arr[i], "rra", 3) || !ft_memcmp(arr[i], "rrb", 3))
			ft_change_instruction(&arr[i], ft_get_next_inst(&arr[i]), "rrr");
		if (ft_inst_matches(arr[i], arr[i + 1], "ra", "rra"))
			ft_change_instruction(&arr[i], arr[i + 1], "");
		if (ft_inst_matches(arr[i], arr[i + 1], "rb", "rrb"))
			ft_change_instruction(&arr[i], arr[i + 1], "");
		if (ft_inst_matches(arr[i], arr[i + 1], "pa", "pb"))
			ft_change_instruction(&arr[i], arr[i + 1], "");
		i ++;
	}
}

void	ft_print_instructions(char *instructions)
{
	char	**arr;
	int		i;

	arr = ft_split(instructions, '\n');
	ft_optimise_instructions(arr);
	i = 0;
	while (arr[i])
	{
		if (*arr[i])
			ft_putendl_fd(arr[i], STDOUT_FILENO);
		i ++;
	}
	arr = ft_free_2d(arr);
}
