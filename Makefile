###########  ###########  ###########  ###          ##########    ###########  ###     ###
###########  ###########  ###########  ###          ###    ###    ###########   ###   ###
    ###      ###     ###  ###     ###  ###          ##########    ###     ###    #######
    ###      ###     ###  ###     ###  ###          ############  ###     ###    #######
    ###      ###########  ###########  ###########  ###      ###  ###########   ###   ###
    ###      ###########  ###########  ###########  ############  ###########  ###     ###

########################
## COMPILER AND FLAGS ##
########################

AR			=	ar rcsT
RM			=	rm -rf
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
DEBUG		= -g3
FLAGS		+= $(DEBUG)
DFLAGS		= -MMD -MP
FLAGS		+= $(DFLAGS)
FFLAGS		=	-fsanitize=address
#FLAGS		+= $(FFLAGS)
IFLAGS		= -Iinclude
FLAGS		+= $(IFLAGS)


#################
## DIRECTORIES ##
#################

BUI_DIR		=	build/
INC_DIR		=	include/
SRC_DIR		=	src/
TES_DIR		=	tests/

LIBFT		=	Libft/

###########
## FILES ##
###########

NAME		=	toolbox.a

LIBFT_A		= $(LIBFT)libft.a

############
## COLORS ##
############

RED			=	\033[1;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
BLUE		=	\033[1;34m
MAGENTA		=	\033[1;35m
CYAN		=	\033[1;36m
RESET		=	\033[0m

###################
## COVERAGE TEST ##
###################

TEST_NAME	=	coverage

TEST_FIL	=	main \
				ft_is/test_ft_isalnum \
				ft_str/test_ft_strdup \
				ft_str/test_ft_strlen

TEST		= $(addprefix $(TES_DIR)$(SRC_DIR), $(addsuffix .c, $(TEST_FIL)))
TEST_OBJ	= $(addprefix $(TES_DIR)$(BUI_DIR), $(addsuffix .o, $(TEST_FIL)))

OBJF		= .cache_exists

#############
## RECIPES ##
#############

# Protection towards relinking
all: $(NAME)

#Merge all static libraries into one
$(NAME): $(LIBFT_A)
	echo "Combinig libraries into $(NAME)..."
	$(AR) $(NAME) $(LIBFT_A)
	echo "$(NAME) Created"

$(LIBFT_A):
	echo "Compiling Libft.a"
	$(MAKE) -C $(LIBFT)

clean:
	echo "Cleaning individual libraries..."
	$(MAKE) clean -C $(LIBFT)
	$(RM) $(TES_DIR)$(BUI_DIR) $(OBJF)

fclean: clean 
	echo "Removing all libraries..."
	$(MAKE) fclean -C $(LIBFT)
	$(RM) $(NAME)
	$(RM) $(TEST_NAME)

re: fclean all

##################
## TEST TARGETS ##
##################

test : $(NAME) $(TEST_NAME)

$(TEST_NAME): $(TEST_OBJ)
	$(CC) $(FLAGS) $(TEST_OBJ) $(NAME) -o $(TEST_NAME)

$(TES_DIR)$(BUI_DIR)%.o: $(TES_DIR)$(SRC_DIR)%.c | $(OBJF)
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJF):
	touch $(OBJF)

-include: $(OBJ:.o=.d)

.PHONY: all clean fclean re
