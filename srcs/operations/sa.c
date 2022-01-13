/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:55:54 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/13 20:03:40 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sa(t_stack *a, t_stack *b, char **instructions)
{
	int	swap;

	if (a->top < 2)
		return ;
	(void)b;
	swap = a->stack[a->top - 1];
	a->stack[a->top - 1] = a->stack[a->top - 2];
	a->stack[a->top - 2] = swap;
	*instructions = ft_strnjoin(*instructions, "sa\n", 3);
}
