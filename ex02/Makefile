NAME = identify_class 
VERBOSE = 1

#CPP_FLAGS = -Wextra -Werror -Wall --std=c++98 -fsanitize=address
CPP_FLAGS = -Wextra -Werror -Wall --std=c++98

CPP_FILES = main.cpp Base.cpp

O_FILES = $(CPP_FILES:%cpp=%o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(O_FILES)
	clang++ $(CPP_FLAGS) $(O_FILES) -o $(NAME)

$(O_FILES):
	clang++ -c -D VERBOSE=$(VERBOSE) $(CPP_FLAGS) $(CPP_FILES)

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
