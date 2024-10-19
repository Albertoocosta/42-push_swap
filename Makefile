NAME = push_swap
CC = cc 
FLAGS = -Wall -Wextra -Werror -g
LIBFT = Libft/libft.a
PRINTF = Printf/libftprintf.a
SRCS = push_swap.c utils_nodes.c utils.c utils_nodes2.c swap.c push.c rev_rotate.c rotate.c sort_three.c

all: $(NAME)

$(LIBFT):
	@make -C Libft

$(PRINTF):
	@make -C Printf

$(NAME):	$(LIBFT) $(PRINTF)
	@$(CC) $(FLAGS) $(SRCS) $(LIBFT) $(PRINTF) -o $(NAME)

clean: 
	@rm -rf *.o
fclean:
	@rm $(NAME)
	@echo ALL CLEAR

re: fclean all