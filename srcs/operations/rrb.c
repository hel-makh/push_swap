/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:39:21 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/13 20:03:43 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rrb(t_stack *a, t_stack *b, char **instructions)
{
	int	i;
	int	rotate;

	if (b->top < 2)
		return ;
	(void)a;
	rotate = b->stack[0];
	i = 1;
	while (i < b->top)
	{
		b->stack[i - 1] = b->stack[i];
		i ++;
	}
	b->stack[i - 1] = rotate;
	*instructions = ft_strnjoin(*instructions, "rrb\n", 4);
}
