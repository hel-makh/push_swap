/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:56:32 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/21 04:07:27 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_quit_checker(int status, t_stacks *stacks)
{
	if (status == EXIT_FAILURE)
		ft_putendl_fd("Error", STDERR_FILENO);
	ft_free(stacks->a.stack);
	ft_free(stacks->b.stack);
	exit(status);
}
