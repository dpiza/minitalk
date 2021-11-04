SRCS_DIR = ./src
OBJS_DIR = ./obj
INCLUDES_DIR = ./includes
LIBFT_DIR = ./libft

CFLAGS = -Wall -Wextra -Werror
LEAKCHECK = -g -fsanitize=address
CC = gcc $(CFLAGS)
LFLAGS = -L./libft -lft
RM = rm -f

NAME = minitalk
NAMESRV = server
NAMECLT = client

SRV_FILES = server.c
SRV_OBJS_FILES = $(SRV_FILES:.c=.o)
SRV_OBJS = $(addprefix $(OBJS_DIR)/, $(SRV_OBJS_FILES))

CLT_FILES = client.c err.c
CLT_OBJS_FILES = $(CLT_FILES:.c=.o)
CLT_OBJS = $(addprefix $(OBJS_DIR)/, $(CLT_OBJS_FILES))

INCLUDES_FILES = minitalk.h
INCLUDES = $(addprefix $(INCLUDES_DIR)/, $(INCLUDES_FILES))

LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

bonus: all

$(NAME): $(NAMESRV) $(NAMECLT)

$(NAMESRV): $(LIBFT) $(SRV_OBJS) $(INCLUDES)
	$(CC) -o $(NAMESRV) $(SRV_OBJS) $(LFLAGS)

$(NAMECLT): $(LIBFT) $(CLT_OBJS) $(INCLUDES)
	$(CC) -o $(NAMECLT) $(CLT_OBJS) $(LFLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR) printf

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES_DIR) $(INCLUDES)
	mkdir -p $(OBJS_DIR)
	$(CC) -I $(INCLUDES_DIR) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAMESRV)
	$(RM) $(NAMECLT)
	rm -rf $(OBJS_DIR)

re: fclean all

.PHONY:	all clean fclean re bonus