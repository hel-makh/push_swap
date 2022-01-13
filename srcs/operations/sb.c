/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:55:54 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/13 20:03:36 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sb(t_stack *a, t_stack *b, char **instructions)
{
	int	swap;

	if (b->top < 2)
		return ;
	(void)a;
	swap = b->stack[b->top - 1];
	b->stack[b->top - 1] = b->stack[b->top - 2];
	b->stack[b->top - 2] = swap;
	*instructions = ft_strnjoin(*instructions, "sb\n", 3);
}
