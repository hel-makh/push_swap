/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 23:28:29 by hel-makh          #+#    #+#             */
/*   Updated: 2022/02/05 23:30:43 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	ft_arrlen(char **arr)
{
	size_t	arrlen;

	arrlen = 0;
	while (arr[arrlen])
		arrlen ++;
	return (arrlen);
}
