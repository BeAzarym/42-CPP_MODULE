NAME	=	megaphone

SRC	=	megaphone.cpp

OBJS		=	$(SRC:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98

CC	=	c++

RM	=	@rm -rf

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)


$(NAME):	$(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all re clean fclean