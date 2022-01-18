/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:51:56 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/18 19:08:13 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_change_instruction(char **instruction, char **next, char *new)
{
	free(*instruction);
	*instruction = ft_strdup(new);
	ft_bzero(*next, ft_strlen(*next));
}

static int	ft_inst_matches(char *inst1, char *inst2, char *comp1, char *comp2)
{
	if (!ft_strncmp(inst1, comp1, ft_strlen(comp1))
		&& !ft_strncmp(inst2, comp2, ft_strlen(comp2)))
		return (1);
	else if (!ft_strncmp(inst1, comp2, ft_strlen(comp2))
		&& !ft_strncmp(inst2, comp1, ft_strlen(comp1)))
		return (1);
	return (0);
}

static void	ft_optimise_instructions(char **arr)
{
	int	i;

	i = 0;
	while (arr[i + 1])
	{
		if (ft_inst_matches(arr[i], arr[i + 1], "sa", "sb"))
			ft_change_instruction(&arr[i], &arr[i + 1], "ss");
		if (ft_inst_matches(arr[i], arr[i + 1], "ra", "rb"))
			ft_change_instruction(&arr[i], &arr[i + 1], "rr");
		if (ft_inst_matches(arr[i], arr[i + 1], "rra", "rrb"))
			ft_change_instruction(&arr[i], &arr[i + 1], "rrr");
		if (ft_inst_matches(arr[i], arr[i + 1], "ra", "rra"))
			ft_change_instruction(&arr[i], &arr[i + 1], "");
		if (ft_inst_matches(arr[i], arr[i + 1], "rb", "rrb"))
			ft_change_instruction(&arr[i], &arr[i + 1], "");
		if (ft_inst_matches(arr[i], arr[i + 1], "pa", "pb"))
			ft_change_instruction(&arr[i], &arr[i + 1], "");
		i ++;
	}
}

void	ft_print_instructions(char *instructions)
{
	char	**arr;
	int		i;

	arr = ft_split(instructions, '\n');
	instructions = ft_free(instructions);
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
