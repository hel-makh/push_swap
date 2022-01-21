/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_instructions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 03:44:42 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/21 04:19:02 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_swap(t_stacks *stacks, char *instruction)
{
	if (instruction[2])
		ft_quit_checker(EXIT_FAILURE, stacks);
	if (!ft_strncmp(instruction, "sa", 2))
		ft_sa(stacks);
	else if (!ft_strncmp(instruction, "sb", 2))
		ft_sb(stacks);
	else if (!ft_strncmp(instruction, "ss", 2))
		ft_ss(stacks);
	else
		ft_quit_checker(EXIT_FAILURE, stacks);
}

void	ft_push(t_stacks *stacks, char *instruction)
{
	if (instruction[2])
		ft_quit_checker(EXIT_FAILURE, stacks);
	if (!ft_strncmp(instruction, "pa", 2))
		ft_pa(stacks);
	else if (!ft_strncmp(instruction, "pb", 2))
		ft_pb(stacks);
	else
		ft_quit_checker(EXIT_FAILURE, stacks);
}

void	ft_shift_up(t_stacks *stacks, char *instruction)
{
	if (instruction[2])
		ft_quit_checker(EXIT_FAILURE, stacks);
	if (!ft_strncmp(instruction, "ra", 2))
		ft_ra(stacks);
	else if (!ft_strncmp(instruction, "rb", 2))
		ft_rb(stacks);
	else if (!ft_strncmp(instruction, "rr", 2))
		ft_rr(stacks);
	else
		ft_quit_checker(EXIT_FAILURE, stacks);
}

void	ft_shift_down(t_stacks *stacks, char *instruction)
{
	if (instruction[3])
		ft_quit_checker(EXIT_FAILURE, stacks);
	if (!ft_strncmp(instruction, "rra", 3))
		ft_rra(stacks);
	else if (!ft_strncmp(instruction, "rrb", 3))
		ft_rrb(stacks);
	else if (!ft_strncmp(instruction, "rrr", 3))
		ft_rrr(stacks);
	else
		ft_quit_checker(EXIT_FAILURE, stacks);
}
