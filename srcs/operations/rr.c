/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:55:54 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/13 20:03:12 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rr(t_stack *a, t_stack *b, char **instructions)
{
	ft_ra(a, b, instructions);
	ft_rb(a, b, instructions);
}
