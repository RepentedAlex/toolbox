########################
## COMPILER AND FLAGS ##
########################

CC			=	gcc
STD			=	-std=c99
WFLAGS		=	-Wall -Wextra -Wno-unused-parameter \
                -Werror \
                -Wno-unused-variable -Wno-unused-function \
                -Wno-unused-value \
                -Wno-unused-label -Wno-unused-local-typedefs \
                -Wno-unused-const-variable -Wno-unused-macros
FFLAGS		=	-fsanitize=address \
				-fno-omit-frame-pointer \
            	-fsanitize=undefined \
            	-fsanitize=leak \
            	-fsanitize=pointer-subtract \
            	-fsanitize=pointer-compare \
            	-fsanitize=pointer-overflow \
CFLAGS		=	$(WFLAGS) $(STD) -MMD -MP -Werror -O3

#################
## DIRECTORIES ##
#################

SRC_DIR		=	src
BUILD_DIR	=	build
INCLUDE		=	include

###########
## FILES ##
###########

NAME		=	$(notdir $(shell pwd))
SRC_FILES	=	
SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			=	$(addprefix $(BUILD_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJF		=	.cache_exists

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

#################
## BONUS FILES ##
#################

BONUS_FILES	=	

BONUS_SRC	=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(BONUS_FILES)))
BONUS_OBJ	=	$(addprefix $(BUILD_DIR), $(addsuffix .o, $(BONUS_FILES)))

#############
## RECIPES ##
#############

# Default target
all: $(NAME)

# Link
$(NAME): $(OBJF) $(OBJ)
	@echo -e "$(BLUE)Linking $@$(RESET)"
	@$(CC) $(CFLAGS) -I$(INCLUDE) $(OBJ) -o $(NAME)
	@echo -e "$(GREEN)Build successful!$(RESET)"

# Compile
$(BUILD_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@echo -e "$(YELLOW)Compiling $<$(RESET)"
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

# Create directories
$(OBJF):
	@echo "$(CYAN)=== CREATING BUILD DIRECTORY ===$(DEF_COLOR)"
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(addprefix $(BUILD_DIR), $(dir $(SRC_FILES)))
	@mkdir -p $(addprefix $(BUILD_DIR), $(dir $(BONUS_FILES)))
	@touch $(OBJF)
	@echo "$(GREEN)!!! Build directory created !!!$(DEF_COLOR)"

bonus: all $(OBJ) $(BONUS_OBJ)
	@

clean:
	@$(RM) $(OBJ) $(BONUS_OBJ) $(OBJF)
	@$(RM) -r $(BUILD_DIR)
	@echo -e "$(RED)Cleaning build files$(RESET)"

fclean: clean 
	@$(RM) $(NAME)
	@echo -e "$(RED)Cleaning binary$(RESET)"

re: fclean all
	
.PHONY: all bonus clean fclean re