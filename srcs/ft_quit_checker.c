/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:56:32 by hel-makh          #+#    #+#             */
/*   Updated: 2022/02/05 19:19:12 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_quit_checker(int status, t_stacks *stacks)
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
