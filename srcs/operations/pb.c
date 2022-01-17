/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:51:46 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/17 19:39:30 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_pb(t_stacks *stacks)
{
	if (stacks->a.top == 0)
		return ;
	stacks->b.stack[stacks->b.top] = stacks->a.stack[stacks->a.top - 1];
	stacks->b.top ++;
	stacks->a.stack[stacks->a.top - 1] = (int) NULL;
	stacks->a.top --;
	stacks->instructions = ft_strnjoin(stacks->instructions, "pb\n", 3);
}
