SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
LIB_FT_PRINTF = ft_printf/libftprintf.a
FT_PRINTF = ft_printf
HEADER = minitalk.h
HEADER_BONUS = minitalk_bonus.h
HEADER_PRINTF = ft_printf/ft_printf.h
HEADER_LIBFT = ft_printf/libft/libft.h
SRCS = $(SERVER).c $(CLIENT).c
SRCS_BONUS = $(SERVER_BONUS).c $(CLIENT_BONUS).c
SRCSDIR = ./srcs
SRCSDIR_BONUS = ./srcs_bonus
OBJDIR = ./objs
HEADERDIR = ./includes
OBJ = $(addprefix $(OBJDIR)/,$(notdir $(SRCS:.c=.o)))
OBJ_BONUS = $(addprefix $(OBJDIR)/,$(notdir $(SRCS_BONUS:.c=.o)))

all:	$(LIB_FT_PRINTF) $(OBJDIR) $(OBJ) $(SERVER) $(CLIENT)

$(OBJDIR)/%.o :	$(SRCSDIR)/%.c $(HEADERDIR)/$(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@

$(OBJDIR)/%.o :	$(SRCSDIR_BONUS)/%.c $(HEADERDIR)/$(HEADER_BONUS)
	@$(CC) $(FLAGS) -c $< -o $@

$(SERVER): $(OBJDIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJDIR)/$(SERVER).o $(LIB_FT_PRINTF) -o $(SERVER)

$(CLIENT): $(OBJDIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJDIR)/$(CLIENT).o $(LIB_FT_PRINTF) -o $(CLIENT)

$(LIB_FT_PRINTF):
	@make -C $(FT_PRINTF)

$(OBJDIR):
	@if [ ! -d $(OBJDIR) ] ; then echo "creating $(OBJDIR)" ; mkdir $(OBJDIR); fi

bonus: $(LIB_FT_PRINTF) $(OBJDIR) $(OBJ_BONUS) $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): $(OBJDIR) $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJDIR)/$(SERVER_BONUS).o $(LIB_FT_PRINTF) -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(OBJDIR) $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJDIR)/$(CLIENT_BONUS).o $(LIB_FT_PRINTF) -o $(CLIENT_BONUS)

clean:
	@make clean -C $(FT_PRINTF)
	@if [ -d $(OBJDIR) ] ; then echo "deleting $(OBJDIR)" ; rm -r $(OBJDIR); fi

fclean:	clean
	@make fclean -C $(FT_PRINTF)
	@rm -f $(SERVER) $(CLIENT)
	@rm -f $(SERVER_BONUS) $(CLIENT_BONUS)

re_bonus: fclean bonus

re:	fclean all

.PHONY:	all clean fclean re bonus