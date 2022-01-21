/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:11:10 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/21 18:20:43 by hel-makh         ###   ########.fr       */
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
	int		j;

	args_count = 0;
	i = 0;
	while (argc >= 0)
	{
		digits = ft_split(argv[argc], ' ');
		j = 0;
		while (digits[j])
			j ++;
		args_count += j;
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
	return_value = 0;
	i = 0;
	while (digits[i])
		i ++;
	while (--i >= 0)
	{
		if (ft_long_atoi(digits[i]) > INT_MAX
			|| ft_long_atoi(digits[i]) < INT_MIN
			|| (ft_atoi(digits[i]) == 0
				&& ft_strncmp(digits[i], "0", ft_strlen(digits[i]))
				&& ft_strncmp(digits[i], "-0", ft_strlen(digits[i]))
				&& ft_strncmp(digits[i], "+0", ft_strlen(digits[i]))))
			return_value += 1;
		stacks->a.stack[*index] = ft_atoi(digits[i]);
		*index += 1;
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
	stacks->b.stack = ft_calloc(args_count, sizeof(int));
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
	stacks.instructions = ft_strdup("");
	if (error)
		ft_quit_program(EXIT_FAILURE, &stacks);
	ft_init_stack_b(&stacks);
	ft_sort_into_stack_a(&stacks);
	ft_print_instructions(stacks.instructions);
	ft_quit_program(EXIT_SUCCESS, &stacks);
}
