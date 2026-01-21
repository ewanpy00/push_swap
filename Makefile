NAME = push_swap
CHECKER = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I.

SRCS = push_swap.c \
	   utils/parse_helpers.c \
	   utils/atoi_utils.c \
	   utils/parse_utils.c \
	   utils/split_utils.c \
	   utils/split_helpers.c \
	   utils/stack_utils.c \
	   operators/swap_ops.c \
	   operators/push_ops.c \
	   operators/rotate_ops.c \
	   operators/reverse_rotate_ops.c \
	   algorighm/chunk_utils.c \
	   algorighm/algorithm.c \
	   algorighm/algorithm_helpers.c \
	   algorighm/position_utils.c \
	   algorighm/cost_utils.c \
	   algorighm/to_stack_a.c \
	   algorighm/to_stack_a_helpers.c

CHECKER_SRCS = checker_push_swap/checker.c \
	   utils/parse_helpers.c \
	   utils/atoi_utils.c \
	   utils/parse_utils.c \
	   utils/split_utils.c \
	   utils/split_helpers.c \
	   utils/stack_utils.c \
	   operators/swap_ops.c \
	   operators/push_ops.c \
	   operators/rotate_ops.c \
	   operators/reverse_rotate_ops.c \
	   algorighm/chunk_utils.c \
	   algorighm/algorithm.c \
	   algorighm/algorithm_helpers.c \
	   algorighm/position_utils.c \
	   algorighm/cost_utils.c \
	   algorighm/to_stack_a.c \
	   algorighm/to_stack_a_helpers.c

OBJS = $(SRCS:.c=.o)
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)
	@rm -f $(OBJS)

checker: $(CHECKER_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(CHECKER_OBJS) -o $(CHECKER)
	@rm -f $(CHECKER_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(CHECKER_OBJS) $(NAME) $(CHECKER)

fclean: clean

re: fclean all

.PHONY: all clean fclean re checker

