/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:51:46 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/17 19:39:28 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_pa(t_stacks *stacks)
{
	if (stacks->b.top == 0)
		return ;
	stacks->a.stack[stacks->a.top] = stacks->b.stack[stacks->b.top - 1];
	stacks->a.top ++;
	stacks->b.stack[stacks->b.top - 1] = (int) NULL;
	stacks->b.top --;
	stacks->instructions = ft_strnjoin(stacks->instructions, "pa\n", 3);
}
