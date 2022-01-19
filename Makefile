HEADER			=	includes/push_swap.h

NAME			=	push_swap

MAIN			=	main.c

SRCS			=	srcs/ft_strnjoin.c\
					srcs/ft_free.c\
					srcs/operations/sa.c\
					srcs/operations/sb.c\
					srcs/operations/ss.c\
					srcs/operations/pa.c\
					srcs/operations/pb.c\
					srcs/operations/ra.c\
					srcs/operations/rb.c\
					srcs/operations/rr.c\
					srcs/operations/rra.c\
					srcs/operations/rrb.c\
					srcs/operations/rrr.c\
					srcs/ft_bubble_sort.c\
					srcs/ft_increment_index.c\
					srcs/ft_decrement_index.c\
					srcs/ft_get_int_index.c\
					srcs/ft_get_biggest_stack_head.c\
					srcs/ft_init_stack_b.c\
					srcs/ft_sort_into_stack_a.c\
					srcs/ft_print_stacks.c\
					srcs/ft_print_instructions.c\
					srcs/ft_quit_program.c

OBJS			=	$(SRCS:.c=.o)\
					$(MAIN:.c=.o)

GCC				=	cc

CFLAGS			=	-Wall -Wextra -Werror

RM				=	rm -f

.c.o:
				$(GCC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):		$(OBJS) $(HEADER)
				make bonus -C Libft
				mv Libft/libft.a ./libft.a
				$(GCC) $(CFLAGS) libft.a $(OBJS) -o $(NAME)

all:			$(NAME)

clean:
				$(RM) $(OBJS) $(OBJS_BONUS)
				make clean -C Libft

fclean:			clean
				$(RM) $(NAME) libft.a

re:				fclean all

.PHONY:			all bonus clean fclean re