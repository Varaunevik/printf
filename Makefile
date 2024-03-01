NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = ft_flags.c ft_helpers.c ft_print_char.c ft_print_int.c ft_print_ptr.c ft_print_string.c ft_print_unsigned.c ft_printf.c ft_print_hex.c ft_safe_write.c ft_safe_putstr.c 
OBJ = $(SRCS:.c=.o) 
RM = rm -f
AR = ar -rcs
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

.PHONY: all clean fclean re bonus

all: $(NAME) $(LIBFT)

$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJ)

$(LIBFT):
	make -C $(LIBFT_PATH)

%.o:%.c ft_printf.h Makefile
	$(CC) -c $(CFLAGS) -o $@ $< -I. -I$(LIBFT_PATH)

bonus: all

clean:
	make clean -C $(LIBFT_PATH)
	$(RM) $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

re: fclean all
