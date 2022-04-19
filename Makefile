NAME	=	push_swap
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g
SRCS	=	main.c push_swap.c check_args.c initialize.c utils.c operations.c bubble_sort.c radix_sort.c tiny_sort.c
OBJ_DIR	=	obj
OBJS	=	$(SRCS:%.c=$(OBJ_DIR)/%.o)
LIBFT_DIR	=	./libft
LIBFT_A	=	$(LIBFT_DIR)/libft.a
LIBFT_FLAG	=	-L./libft -lft
VPATH	=	src
ARG		=	$$(seq 1 200 | shuf | tr '\n' ' ')

all: $(NAME)

clean:
	@rm -rf obj
	@echo "removed obj folder"

fclean: clean
	@rm -rf $(NAME)
	@echo "removed executable"

re: fclean all

check: 
	@arg=$(ARG) && ./push_swap $$arg | ./checker_Mac $$arg

run:
	./push_swap $(ARG)

$(NAME): $(LIBFT_A) $(OBJ_DIR) $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LIBFT_FLAG)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS)  -c $< -o $@ -I ./

$(OBJ_DIR):
	mkdir -p obj

$(LIBFT_A):
	make bonus --directory=$(LIBFT_DIR)