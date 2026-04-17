NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRC			= main.c \
			  linkstack/stack_add_back.c \
			  linkstack/stack_add_front.c \
			  linkstack/stack_clear.c \
			  linkstack/stack_last.c \
			  linkstack/stack_new.c \
			  linkstack/stack_size.c \
			  moves/push.c \
			  moves/stack_a.c \
			  moves/stack_b.c \
			  moves/stack_common.c \
			  utils/ft_error.c \
			  utils/ft_split.c \
			  stack_helper/is_sorted.c\
			  stack_helper/find_position.c\
			  stack_helper/stack_max.c\
			  stack_helper/stack_min.c\
			  algorithms/simple-algo.c \
			  algorithms/min_push_to_b.c\


OBJ_DIR		= obj
OBJ			= $(SRC:%.c=$(OBJ_DIR)/%.o)

HEADER		= push_swap.h
RM			= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re