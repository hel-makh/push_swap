/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:51:56 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/17 17:29:29 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	ft_print_instructions(char *instructions)
{
	char	**arr;
	int		i;

	arr = ft_split(instructions, '\n');
	instructions = ft_free(instructions);
	ft_optimise_instructions(arr);
	i = 0;
	while (arr[i])
		ft_putendl_fd(arr[i++], STDOUT_FILENO);
	arr = ft_free_2d(arr);
}
