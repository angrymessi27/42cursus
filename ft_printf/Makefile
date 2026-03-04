CC = cc
CFLAGS = -Wall -Wextra -Werror
HEAD_FILE = ft_printf.h
SRCS = ft_printf.c is_valid.c print_char.c print_dex.c print_hex.c print_ptr.c \
       print_str.c print_unsign.c
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = ./Libft
NAME = libftprintf.a
  
all: $(NAME)

clean:
	rm -f $(OBJS)
	make fclean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

$(NAME): $(OBJS)
	make all -C $(LIBFT_DIR)
	cp Libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

$(OBJS): $(HEAD_FILE)

.c.o:
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c $< -o $@
	
.PHONY: all clean fclean re
