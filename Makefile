NAME	= program

CC	= g++

RM	= rm -f

SRCS	= ./TekSpice.cpp \
	  ./components/4001.cpp \
	  ./components/Input.cpp \
	  ./components/Output.cpp \
	  ./main.cpp 

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I./pp
CPPFLAGS += -W -Wall -Wextra -g

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
