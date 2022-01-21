/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:39:21 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/20 18:12:09 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rrb(t_stacks *stacks)
{
	int	i;
	int	rotate;

	if (stacks->b.top < 2)
		return ;
	rotate = stacks->b.stack[0];
	i = 1;
	while (i < stacks->b.top)
	{
		stacks->b.stack[i - 1] = stacks->b.stack[i];
		i ++;
	}
	stacks->b.stack[i - 1] = rotate;
}

void	ft_rrb(t_stacks *stacks)
{
	rrb(stacks);
	stacks->instructions = ft_strnjoin(stacks->instructions, "rrb\n", 4);
}
