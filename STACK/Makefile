C = clang++  -std=c++98
FLAG = -Wall -Wextra -Werror
NAME = stack.out
SRCS = stack_tests.cpp

all: $(NAME)

$(NAME): $(SRCS)
			$(C) $(FLAG) $(SRCS) -o $(NAME)

clean:
			rm -rf *.o
fclean : clean
			rm -rf $(NAME)

re: fclean all