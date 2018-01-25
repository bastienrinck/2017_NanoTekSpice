NAME	= program

CC	= g++

RM	= rm -f

SRCS	= ./TekSpice.cpp \
	  ./components/4001.cpp \
	  ./main.cpp 

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I./pp
CPPFLAGS += -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
