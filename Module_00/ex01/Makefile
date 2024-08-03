NAME	= PhoneBook

CXX		= c++
CXXFLAGS	= -Werror -Wextra -Wall -std=c++98

SRC_PATH = ./srcs/
OBJ_PATH = ./objects/
INC_PATH = ./includes/
SRC		= 	main.cpp \
			Contact.cpp \
			PhoneBook.cpp  \
			Utils.cpp
SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.cpp=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INC		= -I $(INC_PATH)

# Main rule
all: $(OBJ_PATH) $(NAME)

# Objects directory rule
$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

# Objects rule
$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INC)

# Project file rule
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@ $(INC)

# Clean up build files rule
clean:
	rm -rf $(OBJ_PATH)

# Remove program executable
fclean: clean
	rm -f $(NAME)

# Clean + remove executable
re: fclean all

.PHONY: all re clean fclean