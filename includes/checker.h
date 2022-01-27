/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:59:08 by hel-makh          #+#    #+#             */
/*   Updated: 2022/01/27 18:22:40 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../Libft/libft.h"

# define BUFFER_SIZE 1

typedef struct s_line
{
	int				fd;
	char			content[BUFFER_SIZE + 1];
	struct s_line	*next;
}	t_line;

typedef struct s_stack {
	int	*stack;
	int	top;
}	t_stack;

typedef struct s_stacks {
	t_stack	a;
	t_stack	b;
}	t_stacks;

long	ft_long_atoi(const char *str);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strnjoin(char const *s1, char const *s2, size_t n);
void	*ft_free(void *ptr);
void	*ft_free_2d(char **ptr);
void	*ft_free_3d(char ***ptr);
char	*get_next_line(int fd);

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

void	ft_swap(t_stacks *stacks, char *instruction);
void	ft_push(t_stacks *stacks, char *instruction);
void	ft_shift_up(t_stacks *stacks, char *instruction);
void	ft_shift_down(t_stacks *stacks, char *instruction);

void	ft_check_instructions(t_stacks *stacks);
void	ft_quit_checker(int status, t_stacks *stacks);

#endif