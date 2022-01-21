/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:05:32 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/20 18:18:13 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rb(t_stacks *stacks)
{
	int	i;
	int	rotate;

	if (stacks->b.top < 2)
		return ;
	rotate = stacks->b.stack[stacks->b.top - 1];
	i = stacks->b.top - 1;
	while (i > 0)
	{
		stacks->b.stack[i] = stacks->b.stack[i - 1];
		i --;
	}
	stacks->b.stack[i] = rotate;
}

void	ft_rb(t_stacks *stacks)
{
	rb(stacks);
	stacks->instructions = ft_strnjoin(stacks->instructions, "rb\n", 3);
}
