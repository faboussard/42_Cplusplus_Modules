NAME = BraiiiiiiinnnzzzZ

CXX	= c++
SRC = main.cpp randomChump.cpp newZombie.cpp Zombie.cpp

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: FLAGS += -g
debug: re

