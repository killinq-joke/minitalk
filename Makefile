NAME	= client
NAME1	= server
SRCS	= client.c
SRCS1	= server.c
OBJS	= $(SRCS=.c:.o)
OBJS1	= $(SRCS1=.c:.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME) $(NAME1)

$(NAME):
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(NAME1):
		$(CC) $(CFLAGS) $(OBJS1) -o $(NAME1)


