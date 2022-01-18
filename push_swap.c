/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:36:32 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/18 12:32:54 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	push_swap(t_stacks *stacks)
{
	int		stack_head;

	stack_head = ft_get_biggest_stack_head(stacks);
	printf("\nstack_head: %d\n\n", stack_head);
	ft_init_stack_b(stacks, stack_head);
	ft_print_stacks(*stacks);
	ft_print_instructions(stacks->instructions);
}
