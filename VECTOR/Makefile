C = clang++  -std=c++98
FLAG = -Wall -Wextra -Werror
NAME = vector.out
SRCS = vector_tests.cpp

all: $(NAME)

$(NAME): $(SRCS)
			$(C) $(FLAG) $(SRCS) -o $(NAME)

clean:
			rm -rf *.o
fclean : clean
			rm -rf $(NAME)

re: fclean all