##
## EPITECH PROJECT, 2023
## test
## File description:
## test
##

NAME =		my_navy

SRC =		main.c			\
		send.c			\
		custom_send.c		\
		receive.c		\
		handling_response.c	\
		generate_map.c		\
		boats.c			\
		my_get_line.c		\
		check_map.c		\
		check_arg.c		\
		check_pos.c		\
		check_contact.c		\

OBJ =		$(SRC:.c=.o)

CFLAGS =	-Wall -Wextra

CPPFLAGS =	-I ./include

LD_LIBRARY_PATH = -L.

LDFLAGS  =	-lmy			\
		-lc			\

LIB_PATH =	./lib/my

all:    $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIB_PATH)
	$(CC) -o $(NAME) $(OBJ) $(LD_LIBRARY_PATH) $(LDFLAGS)

send:
	$(MAKE) -C $(LIB_PATH)
	$(CC) -o sender send.c $(CFLAG) $(LD_LIBRARY_PATH) $(LDFLAGS)

clean:
	rm libmy.a
	rm lib/my/libmy.a
	rm $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all
