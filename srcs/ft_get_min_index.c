/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_min_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:48:05 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/20 13:55:04 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_get_min_index(int *arr, int size)
{
	int	min_index;
	int	min;
	int	i;

	min_index = 0;
	min = arr[min_index];
	i = 0;
	while (i < size)
	{
		if (arr[i] < min)
		{
			min_index = i;
			min = arr[min_index];
		}
		i ++;
	}
	return (min_index);
}
