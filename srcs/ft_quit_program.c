/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:56:32 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/18 22:56:32 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_quit_program(int status, t_stacks *stacks)
{
	ft_free(stacks->a.stack);
	ft_free(stacks->b.stack);
	ft_free(stacks->sorted.stack);
	ft_free(stacks->instructions);
	exit(status);
}
