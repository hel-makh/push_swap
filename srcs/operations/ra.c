/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:05:32 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/13 20:03:51 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_ra(t_stack *a, t_stack *b, char **instructions)
{
	int	i;
	int	rotate;

	if (a->top < 2)
		return ;
	(void)b;
	rotate = a->stack[a->top - 1];
	i = a->top - 1;
	while (i > 0)
	{
		a->stack[i] = a->stack[i - 1];
		i --;
	}
	a->stack[i] = rotate;
	*instructions = ft_strnjoin(*instructions, "ra\n", 3);
}
