NAME = push_swap

BNAME = checker

SRCS = push_swap.c helpers.c lists.c permutations.c sort.c big_sort.c helpers2.c big_sort2.c

BSRCS = checker_bonus/checker_bonus.c checker_bonus/helpers_bonus.c checker_bonus/lists_bonus.c\
	checker_bonus/permutations_bonus.c checker_bonus/split.c\
	checker_bonus/get_next_line.c checker_bonus/get_next_line_utils.c\
	checker_bonus/helpers2_bonus.c

FLAGS = -Werror -Wextra -Wall

OBJ := $(SRCS:.c=.o)

BOBJS := $(BSRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	cc -o $(NAME) $(FLAGS) $(OBJ)

bonus : $(BOBJS)
	cc -o $(BNAME) $(FLAGS) $(BOBJS)

clean :
	rm -rf $(OBJ) $(BOBJS)

fclean : clean
	rm -rf $(NAME) $(BNAME) $(OBJ) $(BOBJS)

re: fclean all