/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:05:32 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/27 18:21:24 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_stacks *stacks)
{
	int	i;
	int	rotate;

	if (stacks->a.top < 2)
		return ;
	rotate = stacks->a.stack[stacks->a.top - 1];
	i = stacks->a.top - 1;
	while (i > 0)
	{
		stacks->a.stack[i] = stacks->a.stack[i - 1];
		i --;
	}
	stacks->a.stack[i] = rotate;
}

void	ft_ra(t_stacks *stacks)
{
	ra(stacks);
	ft_putendl_fd("ra", STDOUT_FILENO);
}
