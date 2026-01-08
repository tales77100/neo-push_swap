FILES = srcs/ft_printf.c \
	srcs/utils.c
	
OBJETS = $(FILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -Iincludes

CC = cc

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJETS)
	ar -csr $(NAME) $(OBJETS)

clean:
	rm -rf $(OBJETS) $(OBJETS_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
