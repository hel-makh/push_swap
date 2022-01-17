/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:55:54 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/17 19:39:35 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sb(t_stacks *stacks)
{
	int	swap;

	if (stacks->b.top < 2)
		return ;
	swap = stacks->b.stack[stacks->b.top - 1];
	stacks->b.stack[stacks->b.top - 1] = stacks->b.stack[stacks->b.top - 2];
	stacks->b.stack[stacks->b.top - 2] = swap;
	stacks->instructions = ft_strnjoin(stacks->instructions, "sb\n", 3);
}
