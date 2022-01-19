/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:11:10 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/19 10:25:40 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>

// #include "srcs/ft_strnjoin.c"
// #include "srcs/ft_free.c"

// #include "srcs/operations/sa.c"
// #include "srcs/operations/sb.c"
// #include "srcs/operations/ss.c"
// #include "srcs/operations/pa.c"
// #include "srcs/operations/pb.c"
// #include "srcs/operations/ra.c"
// #include "srcs/operations/rb.c"
// #include "srcs/operations/rra.c"
// #include "srcs/operations/rrb.c"
// #include "srcs/operations/rrr.c"

// #include "srcs/ft_bubble_sort.c"
// #include "srcs/ft_increment_index.c"
// #include "srcs/ft_decrement_index.c"
// #include "srcs/ft_get_int_index.c"
// #include "srcs/ft_get_biggest_stack_head.c"

// #include "srcs/ft_init_stack_b.c"
// #include "srcs/ft_sort_into_stack_a.c"
// #include "srcs/ft_print_stacks.c"
// #include "srcs/ft_print_instructions.c"
// #include "srcs/ft_quit_program.c"

static void	push_swap(t_stacks *stacks)
{
	ft_init_stack_b(stacks);
	// ft_print_stacks(*stacks);
	ft_sort_into_stack_a(stacks);
	// ft_print_stacks(*stacks);
	ft_print_instructions(stacks->instructions);
}

static void	ft_create_stacks(t_stacks *stacks, int size, char *argv[])
{
	int		i;

	stacks->a.stack = ft_calloc(size, sizeof(int));
	stacks->b.stack = ft_calloc(size, sizeof(int));
	i = 0;
	while (size >= 0)
		stacks->a.stack[i++] = ft_atoi(argv[size--]);
	stacks->a.top = i - 1;
	stacks->b.top = 0;
}

static int	ft_is_arg_valid(int argc, char *argv[])
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
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-')
				return (0);
			j ++;
		}
		k = i + 1;
		while (k < argc)
		{
			if (!ft_strncmp(argv[k], argv[i], ft_strlen(argv[k]))
				&& !ft_strncmp(argv[k], argv[i], ft_strlen(argv[i])))
				return (0);
			k ++;
		}
		i ++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stacks	stacks;

	if (argc < 2)
		return (EXIT_FAILURE);
	if (!ft_is_arg_valid(argc, argv))
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	ft_create_stacks(&stacks, argc - 1, argv);
	stacks.sorted = ft_sort(stacks.a);
	stacks.instructions = ft_strdup("");
	push_swap(&stacks);
	ft_quit_program(EXIT_SUCCESS, &stacks);
}
