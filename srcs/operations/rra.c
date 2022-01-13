/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:39:26 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/13 12:43:12 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rra(t_stack *a, t_stack *b)
{
	int	i;
	int	rotate;

	if (a->top < 2)
		return ;
	(void)b;
	rotate = a->stack[0];
	i = 1;
	while (i < a->top)
	{
		a->stack[i - 1] = a->stack[i];
		i ++;
	}
	a->stack[i - 1] = rotate;
}
