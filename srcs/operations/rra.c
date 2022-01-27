/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:39:26 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/27 18:21:50 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rra(t_stacks *stacks)
{
	int	i;
	int	rotate;

	if (stacks->a.top < 2)
		return ;
	rotate = stacks->a.stack[0];
	i = 1;
	while (i < stacks->a.top)
	{
		stacks->a.stack[i - 1] = stacks->a.stack[i];
		i ++;
	}
	stacks->a.stack[i - 1] = rotate;
}

void	ft_rra(t_stacks *stacks)
{
	rra(stacks);
	ft_putendl_fd("rra", STDOUT_FILENO);
}
