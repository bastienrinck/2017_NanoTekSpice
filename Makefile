NAME	= nanotekspice

CC	= g++

RM	= rm -f

SRCS	= ./TekSpice.cpp \
		./Logic.cpp \
		./components/4001.cpp \
		./components/4008.cpp \
		./components/4011.cpp \
		./components/4030.cpp \
		./components/4069.cpp \
		./components/4071.cpp \
		./components/4081.cpp \
		./components/4514.cpp \
		./components/Input.cpp \
		./components/Output.cpp \
		./components/Clock.cpp \
		./components/True.cpp \
		./components/False.cpp \
		./parser/Parser.cpp \
		./compute/Simulator.cpp \
		./main.cpp 

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I./pp
CPPFLAGS += -W -Wall -Wextra -g -std=c++11

LDFLAGS += -std=c++11

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
