/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:59:08 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/18 14:32:12 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../Libft/libft.h"

typedef struct s_stack {
    int	*stack;
	int	top;
}	t_stack;

typedef struct s_stacks {
	t_stack	a;
	t_stack	b;
	t_stack	sorted;
	char	*instructions;
}	t_stacks;

char	*ft_strnjoin(char const *s1, char const *s2, size_t n);
void	*ft_free(void *ptr);
void	*ft_free_2d(char **ptr);
void	*ft_free_3d(char ***ptr);

void    ft_sa(t_stacks *stacks);
void	ft_sb(t_stacks *stacks);
void	ft_ss(t_stacks *stacks);
void	ft_pa(t_stacks *stacks);
void	ft_pb(t_stacks *stacks);
void	ft_ra(t_stacks *stacks);
void	ft_rb(t_stacks *stacks);
void	ft_rr(t_stacks *stacks);
void	ft_rra(t_stacks *stacks);
void	ft_rrb(t_stacks *stacks);
void	ft_rrr(t_stacks *stacks);

t_stack	ft_sort(t_stack st);
int     ft_get_int_index(t_stack st, int nb);
int		ft_get_biggest_stack_head(t_stacks *stacks);
int		ft_increment_index(t_stack st, int index, int inc_by);
int		ft_decrement_index(t_stack st, int index, int dec_by);

void	push_swap(t_stacks *stacks);
void	ft_init_stack_b(t_stacks *stacks);
void	ft_print_stacks(t_stacks stacks); // TEST
void	ft_print_instructions(char *instructions);

#endif