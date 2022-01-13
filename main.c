/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:11:10 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/11 13:03:32 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>

#include "srcs/sa.c"
#include "srcs/sb.c"
#include "srcs/ss.c"
#include "srcs/pa.c"
#include "srcs/pb.c"
#include "srcs/ra.c"
#include "srcs/rb.c"
#include "srcs/rra.c"
#include "srcs/rrb.c"
#include "srcs/rrr.c"

void	push_swap(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	int		i;

	a.stack = ft_calloc(argc - 1, sizeof(int));
	b.stack = ft_calloc(argc - 1, sizeof(int));
	i = 1;
	while (i < argc)
	{
		a.stack[i - 1] = ft_atoi(argv[i]);
		i ++;
	}
	a.top = i - 1;
	b.top = 0;

	// b.stack[0] = 2;
	// b.stack[1] = 20;
	// b.stack[2] = 65;
	// b.top = 3;

	// ft_sa(&a, &b);

	// i = 0;
	// while (i < a.top)
	// 	printf("%d\n", a.stack[i++]);
	// puts("\n");
	// i = 0;
	// while (i < b.top)
	// 	printf("%d\n", b.stack[i++]);
}

int	ft_is_arg_valid(int argc, char *argv[])
{
	int	i;
	int	j;
	int	k;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j ++;
		}
		k = i + 1;
		while (k < argc)
		{
			if (ft_atoi(argv[k]) == ft_atoi(argv[i]))
				return (0);
			k ++;
		}
		i ++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
		return (EXIT_FAILURE);
	if (!ft_is_arg_valid(argc, argv))
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	push_swap(argc, argv);
	return (EXIT_SUCCESS);
}
