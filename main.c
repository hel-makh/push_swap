/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:11:10 by hel-makh          #+#    #+#             */
/*   Updated: 2022/02/05 23:30:25 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int	ft_check_duplicates(t_stack st)
{
	int	i;
	int	j;

	i = 0;
	while (i < st.top)
	{
		j = i + 1;
		while (j < st.top)
		{
			if (st.stack[i] == st.stack[j])
				return (1);
			j ++;
		}
		i ++;
	}
	return (0);
}

static int	ft_args_count(char *argv[], int argc)
{
	char	**digits;
	int		args_count;
	int		i;

	args_count = 0;
	while (argc >= 0)
	{
		digits = ft_split(argv[argc], ' ');
		if (!digits)
			exit(EXIT_FAILURE);
		i = 0;
		while (digits[i])
			i ++;
		args_count += i;
		digits = ft_free_2d(digits);
		argc --;
	}
	return (args_count);
}

static int	ft_args_iter(t_stacks *stacks, char *argv, int *index)
{
	char	**digits;
	int		return_value;
	int		i;

	if (!*argv)
		return (1);
	digits = ft_split(argv, ' ');
	if (!digits)
		ft_quit_program(EXIT_FAILURE, stacks);
	return_value = 0;
	i = ft_arrlen(digits);
	while (--i >= 0)
	{
		while (*digits[i] == ' ')
			*(digits + i) += 1;
		if (ft_atoi_ld(digits[i]) > INT_MAX || ft_atoi_ld(digits[i]) < INT_MIN
			|| !ft_isint(digits[i]) || (ft_atoi(digits[i]) == 0
				&& ft_strncmp(digits[i], "0", 1)
				&& ft_strncmp(digits[i], "-0", 2)
				&& ft_strncmp(digits[i], "+0", 2)))
			return_value += 1;
		stacks->a.stack[(*index)++] = ft_atoi(digits[i]);
	}
	digits = ft_free_2d(digits);
	return (return_value);
}

static int	ft_create_stacks(t_stacks *stacks, char *argv[], int size)
{
	int	return_value;
	int	args_count;
	int	i;

	return_value = 0;
	args_count = ft_args_count(argv, size);
	stacks->a.stack = ft_calloc(args_count, sizeof(int));
	if (!stacks->a.stack)
		exit(EXIT_FAILURE);
	stacks->b.stack = ft_calloc(args_count, sizeof(int));
	if (!stacks->b.stack)
	{
		stacks->a.stack = ft_free(stacks->a.stack);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (size > 0)
	{
		return_value += ft_args_iter(stacks, argv[size], &i);
		size --;
	}
	stacks->a.top = i;
	stacks->b.top = 0;
	return (return_value);
}

int	main(int argc, char *argv[])
{
	t_stacks	stacks;
	int			error;

	if (argc == 1)
		return (EXIT_FAILURE);
	error = ft_create_stacks(&stacks, argv, argc - 1);
	error += ft_check_duplicates(stacks.a);
	if (error)
		ft_quit_program(2, &stacks);
	ft_init_stack_b(&stacks);
	ft_sort_into_stack_a(&stacks);
	ft_quit_program(EXIT_SUCCESS, &stacks);
}
