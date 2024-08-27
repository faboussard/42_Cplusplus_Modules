CXX     = c++
SRCS     = main.cpp AAnimal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
OBJS = $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.cpp=.o)))
OBJS_DIR = .objs/
DEPS = $(OBJS:.o=.d)
NAME    = aanimal

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJS_DIR)%.o: %.cpp Makefile
	@mkdir -p $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@ -MMD -MP

-include $(DEPS)

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

debug: CXXFLAGS += -g
debug: re

.PHONY: all clean fclean re debug
