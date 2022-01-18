/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:36:32 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/18 14:31:59 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	push_swap(t_stacks *stacks)
{
	ft_init_stack_b(stacks);
	ft_print_stacks(*stacks);
	ft_print_instructions(stacks->instructions);
}
