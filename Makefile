NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra -g 

SRC = main.c \
	check_stack.c \
	comp.c \
	operation_a.c \
	operation_b.c \
	utils_three.c \
	utils_two.c \
	utils.c \
	ft_split.c \
	check_arg.c \

all: $(NAME)

$(NAME): $(SRC:.c=.o)
	@$(CC) -I . $(CFLAGS) $(SRC) -o $(NAME)

%.o: %.c
	cc $(CFLAGS) -I . -c $< -o $@

clean:
	@rm -rf $(SRC:.c=.o)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re