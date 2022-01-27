/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:55:54 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/27 18:22:15 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_stacks *stacks)
{
	int	swap;

	if (stacks->a.top < 2)
		return ;
	swap = stacks->a.stack[stacks->a.top - 1];
	stacks->a.stack[stacks->a.top - 1] = stacks->a.stack[stacks->a.top - 2];
	stacks->a.stack[stacks->a.top - 2] = swap;
}

void	ft_sa(t_stacks *stacks)
{
	sa(stacks);
	ft_putendl_fd("sa", STDOUT_FILENO);
}
