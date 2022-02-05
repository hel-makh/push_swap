/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:56:32 by hel-makh          #+#    #+#             */
/*   Updated: 2022/02/05 18:56:50 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_quit_program(int status, t_stacks *stacks)
{
	if (status == 2)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		status = EXIT_FAILURE;
	}
	ft_free(stacks->a.stack);
	ft_free(stacks->b.stack);
	exit(status);
}
