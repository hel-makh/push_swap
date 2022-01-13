/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:05:32 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/13 20:03:48 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rb(t_stack *a, t_stack *b, char **instructions)
{
	int	i;
	int	rotate;

	if (b->top < 2)
		return ;
	(void)a;
	rotate = b->stack[b->top - 1];
	i = b->top - 1;
	while (i > 0)
	{
		b->stack[i] = b->stack[i - 1];
		i --;
	}
	b->stack[i] = rotate;
	*instructions = ft_strnjoin(*instructions, "rb\n", 3);
}
