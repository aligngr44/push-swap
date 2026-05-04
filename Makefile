NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRC			= main.c \
			  bench.c \
			  bench_utils.c \
			  stack_add_back.c \
			  stack_add_front.c \
			  stack_clear.c \
			  stack_last.c \
			  stack_new.c \
			  stack_size.c \
			  push.c \
			  stack_a.c \
			  stack_b.c \
			  stack_common.c \
			  ft_error.c \
			  ft_split.c \
			  free_split.c \
			  ft_atol.c \
			  ft_strcmp.c \
			  indexing.c \
			  is_sorted.c \
			  find_position.c \
			  stack_max.c \
			  stack_min.c \
			  simple_algo.c \
			  algo_helpers.c \
			  medium-algo.c \
			  medium-algo2.c \
			  radix_algo.c \
			  adaptive.c \
			  is_number_string.c \
			  the_same.c \
			  add_number_to_stack.c \
			  parse_arg.c \
			  parse_input.c \
			  m_push.c \
			  m_stack_a.c \
			  m_stack_b.c \
			  m_stack_common.c

OBJ			= $(SRC:.c=.o)

HEADER		= push_swap.h
RM			= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re