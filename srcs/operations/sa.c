/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:55:54 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/17 19:39:35 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sa(t_stacks *stacks)
{
	int	swap;

	if (stacks->a.top < 2)
		return ;
	swap = stacks->a.stack[stacks->a.top - 1];
	stacks->a.stack[stacks->a.top - 1] = stacks->a.stack[stacks->a.top - 2];
	stacks->a.stack[stacks->a.top - 2] = swap;
	stacks->instructions = ft_strnjoin(stacks->instructions, "sa\n", 3);
}
