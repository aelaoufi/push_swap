NAME = push_swap

BNAME = checker

SRCS = push_swap.c helpers.c lists.c permutations.c sort.c big_sort.c helpers2.c big_sort2.c

BSRCS = checker/checker.c checker/helpers_bonus.c checker/lists_bonus.c checker/permutations_bonus.c

FLAGS = -Werror -Wextra -Wall

OBJ := $(SRCS:.c=.o)

BOBJS := $(BSRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	cc -o $(NAME) $(FLAGS) $(OBJ)

bonus : $(BOBJS)
	cc -o $(BNAME) $(FLAGS) $

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME) $(OBJ)

re: fclean all