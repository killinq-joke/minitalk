NAME	= client
NAME1	= server
LIB		= libft.a
SRCS	= client.c
SRCS1	= server.c
OBJS	= $(SRCS=c:o)
OBJS1	= $(SRCS1=c:o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

.PHONY: all
all:	$(NAME) $(NAME1) $(LIB)

%.o: %.c
		$(CC) $(CFLAGS) -c $<

$(NAME):	$(OBJS) $(LIB)

$(NAME1):	$(OBJS1) $(LIB)

$(LIB):
		make -C libft/
		mv libft/libft.a .

clean:
	make -C libft/ clean
	$(RM) $(OBJS) $(LIB)

fclean: clean
	make -C libft/ fclean
	$(RM) $(NAME) $(NAME1)

re: fclean all
