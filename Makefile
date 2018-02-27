NAME	= program

CC	= g++

RM	= rm -f

SRCS	= ./TekSpice.cpp \
	  ./components/4001.cpp \
	  ./components/4008.cpp \
	  ./components/4011.cpp \
	  ./components/4030.cpp \
	  ./components/4069.cpp \
	  ./components/4071.cpp \
	  ./components/4081.cpp \
	  ./components/Input.cpp \
	  ./components/Output.cpp \
	  ./parser/Parser.cpp \
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
