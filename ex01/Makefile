NAME = serialise
VERBOSE = 1

#CPP_FLAGS = -Wextra -Werror -Wall --std=c++98 -fsanitize=address
CPP_FLAGS = -Wextra -Werror -Wall --std=c++98

CPP_FILES = main.cpp Serialiser.cpp
HPP_FILES = Serialiser.hpp

O_FILES = $(CPP_FILES:%cpp=%o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(O_FILES) $(HPP_FILES)
	clang++ $(CPP_FLAGS) $(O_FILES) -o $(NAME)

$(O_FILES): $(HPP_FILES)
	clang++ -c -D VERBOSE=$(VERBOSE) $(CPP_FLAGS) $(CPP_FILES)

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
