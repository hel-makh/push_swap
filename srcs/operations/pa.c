/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:51:46 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/13 20:03:54 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_pa(t_stack *a, t_stack *b, char **instructions)
{
	if (b->top == 0)
		return ;
	a->stack[a->top] = b->stack[b->top - 1];
	a->top ++;
	b->stack[b->top - 1] = (int) NULL;
	b->top --;
	*instructions = ft_strnjoin(*instructions, "pa\n", 3);
}
