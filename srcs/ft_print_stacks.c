/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:28:31 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/18 13:04:30 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_stacks(t_stacks stacks)
{
	int	i;

	i = stacks.a.top - 1;
	while (i >= 0)
		printf("a: %d\n", stacks.a.stack[i--]);
	printf("\n");
	i = stacks.b.top - 1;
	while (i >= 0)
		printf("b: %d\n", stacks.b.stack[i--]);
	printf("\n");
}
