NAME = libft.a

HEAD = -I libft.h

SRC_BONUS = $(wildcard *bonus.c)

CC = gcc

SRC = $(filter-out $(SRC_BONUS), $(wildcard *.c))

OBJS = $(patsubst %.c,%.o, $(SRC))

OBJS_BONUS = $(patsubst %.c,%.o, $(SRC_BONUS))

FLAGS = -Wall -Wextra -Werror

RM = rm -f

all : $(NAME)

%.o : %.c %.h
	@$(CC) $(FLAGS) $(HEAD) -c $< -o $@

$(NAME) : $(OBJS)
	@ar rs $(NAME) $(OBJS) $?

bonus : $(OBJS_BONUS)
	@ar rs $(NAME) $(OBJS_BONUS) $?


clean :
	@$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all bonus

.PHONY : all clean fclean re bonus