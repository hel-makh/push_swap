/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:59:08 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/13 20:52:40 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
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
}	t_stacks;

char	*ft_strnjoin(char const *s1, char const *s2, size_t n);
void	*ft_free(void *ptr);
void	*ft_free_2d(char **ptr);
void	*ft_free_3d(char ***ptr);
void	push_swap(t_stacks *stacks);
void    ft_sa(t_stack *a, t_stack *b, char **instructions);
void	ft_sb(t_stack *a, t_stack *b, char **instructions);
void	ft_ss(t_stack *a, t_stack *b, char **instructions);
void	ft_pa(t_stack *a, t_stack *b, char **instructions);
void	ft_pb(t_stack *a, t_stack *b, char **instructions);
void	ft_ra(t_stack *a, t_stack *b, char **instructions);
void	ft_rb(t_stack *a, t_stack *b, char **instructions);
void	ft_rr(t_stack *a, t_stack *b, char **instructions);
void	ft_rra(t_stack *a, t_stack *b, char **instructions);
void	ft_rrb(t_stack *a, t_stack *b, char **instructions);
void	ft_rrr(t_stack *a, t_stack *b, char **instructions);
int     ft_get_int_index(t_stack st, int nb);
t_stack	ft_sort(t_stack st);

#endif