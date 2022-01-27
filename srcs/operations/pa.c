/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:51:46 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/27 18:18:59 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(t_stacks *stacks)
{
	if (stacks->b.top == 0)
		return ;
	stacks->a.stack[stacks->a.top] = stacks->b.stack[stacks->b.top - 1];
	stacks->a.top ++;
	stacks->b.stack[stacks->b.top - 1] = 0;
	stacks->b.top --;
}

void	ft_pa(t_stacks *stacks)
{
	pa(stacks);
	ft_putendl_fd("pa", STDOUT_FILENO);
}
