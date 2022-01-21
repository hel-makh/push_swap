/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:39:16 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/20 18:14:19 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rrr(t_stacks *stacks)
{
	rra(stacks);
	rrb(stacks);
}

void	ft_rrr(t_stacks *stacks)
{
	rrr(stacks);
	stacks->instructions = ft_strnjoin(stacks->instructions, "rrr\n", 4);
}
