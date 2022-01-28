HEADER			=	includes/push_swap.h

NAME			=	push_swap

MAIN			=	main.c

SRCS			=	srcs/ft_long_atoi.c\
					srcs/ft_free.c\
					srcs/ft_get_min_index.c\
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
					srcs/ft_get_min.c\
					srcs/ft_increment_index.c\
					srcs/ft_decrement_index.c\
					srcs/ft_get_int_index.c\
					srcs/ft_get_biggest_stack_head.c\
					srcs/ft_init_stack_b.c\
					srcs/ft_sort_into_stack_a.c\
					srcs/ft_quit_program.c

OBJS			=	$(SRCS:.c=.o)\
					$(MAIN:.c=.o)

HEADER_BONUS	=	includes/checker.h

NAME_BONUS		=	checker

MAIN_BONUS		=	checker.c

SRCS_BONUS		=	srcs/ft_long_atoi.c\
					srcs/ft_strcpy.c\
					srcs/ft_strnjoin.c\
					srcs/ft_free.c\
					srcs/get_next_line.c\
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
					srcs/ft_check_instructions.c\
					srcs/ft_checker_instructions.c\
					srcs/ft_quit_checker.c

OBJS_BONUS		=	$(SRCS_BONUS:.c=.o)\
					$(MAIN_BONUS:.c=.o)

LIBFT			=	./Libft

LIB				=	./Libft/libft.a

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror

RM				=	rm -f

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):		$(OBJS) $(HEADER) $(LIB)
				$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

bonus:			$(OBJS_BONUS) $(HEADER_BONUS) $(LIB)
				$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIB) -o $(NAME_BONUS)

all:			$(NAME)

$(LIB):
				make bonus -C $(LIBFT)

clean:
				$(RM) $(OBJS) $(OBJS_BONUS)
				make clean -C Libft

fclean:			clean
				$(RM) $(NAME) $(NAME_BONUS)
				make fclean -C Libft

re:				fclean all

.PHONY:			all bonus clean fclean re