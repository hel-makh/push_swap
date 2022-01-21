/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 03:19:33 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/21 19:02:10 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int	ft_is_sorted(t_stacks *stacks)
{
	int	nb;
	int	i;

	nb = stacks->a.stack[0];
	i = 0;
	while (i < stacks->a.top)
	{
		if (stacks->a.stack[i] > nb)
			return (0);
		nb = stacks->a.stack[i];
		i ++;
	}
	return (1);
}

static void	ft_apply_instructions(t_stacks *stacks, char *instructions)
{
	char	**inst_array;
	int		i;

	inst_array = ft_split(instructions, '\n');
	i = 0;
	while (inst_array[i])
	{
		if (inst_array[i][0] == 's')
			ft_swap(stacks, inst_array[i]);
		else if (inst_array[i][0] == 'p')
			ft_push(stacks, inst_array[i]);
		else if ((inst_array[i][0] == 'r' && inst_array[i][1] != 'r')
			|| (inst_array[i][0] == 'r'
				&& inst_array[i][1] == 'r'
				&& !inst_array[i][2]))
			ft_shift_up(stacks, inst_array[i]);
		else if (inst_array[i][0] == 'r'
			&& inst_array[i][1] == 'r'
			&& inst_array[i][2])
			ft_shift_down(stacks, inst_array[i]);
		else
			ft_quit_checker(EXIT_FAILURE, stacks);
		i ++;
	}
	inst_array = ft_free_2d(inst_array);
}

void	ft_check_instructions(t_stacks *stacks)
{
	char	*instruction;
	char	*instructions;

	instructions = ft_strdup("");
	while (1)
	{
		instruction = get_next_line(STDIN_FILENO);
		if (!instruction)
			break ;
		instructions = ft_strnjoin(instructions, instruction,
				ft_strlen(instruction));
		instruction = ft_free(instruction);
	}
	ft_apply_instructions(stacks, instructions);
	instructions = ft_free(instructions);
	if (ft_is_sorted(stacks) && !stacks->b.top)
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
}
