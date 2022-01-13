/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:39:16 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/13 20:03:22 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rrr(t_stack *a, t_stack *b, char **instructions)
{
	ft_rra(a, b, instructions);
	ft_rrb(a, b, instructions);
}
