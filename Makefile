############
## COLORS ##
############

DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

###############
## VARIABLES ##
###############

NAME		=	
CC			=	
SRC_DIR		=	src
BUILD_DIR	=	build
INCLUDE		=	include

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

#############
## SOURCES ##
#############

SRC_FILES	=	

SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			=	$(addprefix $(BUILD_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF		=	.cache_exists

###########
## BONUS ##
###########

BONUS_FILES	=	

BONUS_SRC	=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(BONUS_FILES)))
BONUS_OBJ	=	$(addprefix $(BUILD_DIR), $(addsuffix .o, $(BONUS_FILES)))

#############
## RECIPES ##
#############

all: $(NAME)

$(NAME): $(OBJF) $(OBJ)
	@echo "$(CYAN)=== COMPILING $(NAME) ===$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -I$(INCLUDE) $(OBJ) -o $(NAME)
	@echo "$(GREEN)!!! $(NAME) COMPILED !!!$(DEF_COLOR)"

$(BUILD_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@echo "$(CYAN)=== COMPILING $< ===$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

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
	@echo "$(MAGENTA)!!! BUILD FILES REMOVED !!!$(DEF_COLOR)"

fclean: clean 
	@$(RM) $(NAME)
	@echo "$(MAGENTA)!!! $(NAME) REMOVED !!!$(DEF_COLOR)"

re: fclean all
	
.PHONY: all bonus clean fclean re