NAME = libftprintf.a
LIBFT = libft/libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
HEADER = ft_printf.h
LIBFT_DIR = libft
SRC = ft_printf.c ft_funk.c ft_funk2.c
OBJ = $(SRC:.c=.o)
.c.o:
	@$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all:    $(LIBFT) $(NAME)

$(NAME):	$(OBJ) $(HEADER)
	@ar -rc $(NAME) $(OBJ) $(LIBFT_DIR)/*.o

$(LIBFT):
	@make -C $(LIBFT_DIR)
		
clean:
	@make clean -C $(LIBFT_DIR)
	@rm -f $(OBJ)
fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re