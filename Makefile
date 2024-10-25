NAME = push_swap
CC = cc 
FLAGS = -Wall -Wextra -Werror -g
LIBFT = Libft/libft.a
PRINTF = Printf/libftprintf.a
SRCS = push_swap.c utils_nodes.c utils.c utils_nodes2.c swap.c push.c rev_rotate.c rotate.c sort_three.c sortstacks.c a_to_b.c b_to_a.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	@make -C Libft

$(PRINTF):
	@make -C Printf

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean: 
	@rm -rf *.o
fclean: clean
	@rm $(NAME)
	@echo ALL CLEAR

re: fclean all