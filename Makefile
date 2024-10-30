NAME = push_swap
CC = cc 
FLAGS = -Wall -Wextra -Werror -g
LIBFT_SRCS = $(wildcard Libft/*.c)
PRINTF_SRCS = $(wildcard Printf/*.c)
SRCS = push_swap.c utils_nodes.c utils.c utils_nodes2.c swap.c push.c rev_rotate.c rotate.c sort_three.c sortstacks.c a_to_b.c b_to_a.c
OBJS = $(SRCS:.c=.o)
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_OBJS) $(PRINTF_OBJS)
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT_OBJS) $(PRINTF_OBJS) -o $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean: 
	@rm -f *.o Libft/*.o Printf/*.o

fclean: clean
	@rm -f $(NAME)
	@echo ALL CLEAR

re: fclean all