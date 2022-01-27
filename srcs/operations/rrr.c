/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:39:16 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/27 18:22:10 by hel-makh         ###   ########.fr       */
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
	ft_putendl_fd("rrr", STDOUT_FILENO);
}
