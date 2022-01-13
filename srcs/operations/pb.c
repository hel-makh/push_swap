/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:51:46 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/13 20:03:52 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_pb(t_stack *a, t_stack *b, char **instructions)
{
	if (a->top == 0)
		return ;
	b->stack[b->top] = a->stack[a->top - 1];
	b->top ++;
	a->stack[a->top - 1] = (int) NULL;
	a->top --;
	*instructions = ft_strnjoin(*instructions, "pb\n", 3);
}
