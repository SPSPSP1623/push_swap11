CC = cc
CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

NAME = libftprintf.a

SRCS = ft_printf.c ft_format_id.c ft_print_c.c ft_print_di.c ft_print_s.c ft_print_u.c ft_print_x.c ft_print_p.c
OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
		$(CC) $(CFLAGS) -I includes/ -c $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

