/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:59:08 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/27 18:36:49 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../Libft/libft.h"

typedef struct s_stack {
	int	*stack;
	int	top;
}	t_stack;

typedef struct s_stacks {
	t_stack	a;
	t_stack	b;
}	t_stacks;

long	ft_long_atoi(const char *str);
char	*ft_strnjoin(char const *s1, char const *s2, size_t n);
void	*ft_free(void *ptr);
void	*ft_free_2d(char **ptr);
void	*ft_free_3d(char ***ptr);
int		ft_get_min_index(int *arr, int size);

void	sa(t_stacks *stacks);
void	ft_sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ft_sb(t_stacks *stacks);
void	ss(t_stacks *stacks);
void	ft_ss(t_stacks *stacks);
void	pa(t_stacks *stacks);
void	ft_pa(t_stacks *stacks);
void	pb(t_stacks *stacks);
void	ft_pb(t_stacks *stacks);
void	ra(t_stacks *stacks);
void	ft_ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	ft_rb(t_stacks *stacks);
void	rr(t_stacks *stacks);
void	ft_rr(t_stacks *stacks);
void	rra(t_stacks *stacks);
void	ft_rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	ft_rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);
void	ft_rrr(t_stacks *stacks);

int		ft_increment_index(t_stack st, int index, int inc_by);
int		ft_decrement_index(t_stack st, int index, int dec_by);
int		ft_get_min(t_stack st);
int		ft_get_int_index(t_stack st, int nb);
int		ft_get_biggest_stack_head(t_stacks *stacks);

void	ft_init_stack_b(t_stacks *stacks);
void	ft_sort_into_stack_a(t_stacks *stacks);
void	ft_quit_program(int status, t_stacks *stacks);

#endif