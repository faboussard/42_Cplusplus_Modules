CXX     = c++
SRC     = main.cpp randomChump.cpp newZombie.cpp Zombie.cpp
OBJ     = $(SRC:.cpp=.o)
DEPS = $(OBJ:.o=.d)
NAME    = BraiiiiiiinnnzzzZ

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -MMD -MP

-include $(DEPS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: CXXFLAGS += -g
debug: re

.PHONY: all clean fclean re debug
