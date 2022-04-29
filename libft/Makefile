# ###################COMMAND#############################
CC=cc
CFLAGS=-Wall -Wextra -Werror -g
RM = rm -f
AR    := ar rcs
# ###################PATH#############################
SRC_DIR = src
INCLUDE_DIR = include

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:.c=.o)
INCLUDES = $(wildcard $(INCLUDE_DIR)/*)
OBJ_DIR = $(addprefix obj/, $(notdir $(OBJS)))
NAME = libft.a
MAIN = main.c
EXEC = main
# ################COLOR##############################
COLOR='\033[0;32m'
NC='\033[0m' # No Color
RE= '\033[0;34m'
# ###################################################
all: $(NAME) 
	
obj/%.o: src/%.c $(INCLUDES)
	@ $(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o obj/$(notdir $@)
	
WAITING : 
	@ echo ${COLOR}"LIBRARY OF LIBFT IS CREATING ..."${NC}

$(NAME): WAITING $(OBJ_DIR) $(INCLUDES) 
	@ $(AR) library/$(NAME) $(OBJ_DIR)
	@ echo ${COLOR}"LIBFT LIBRARY CREATED"${NC}

TEST :
	@ $(CC) $(CFLAGS) $(MAIN)  -I $(INCLUDE_DIR) -o $(EXEC) library/$(NAME)
	@ echo ${COLOR}"EXECUTBLE DONE"${NC}
	@ printf  ${RE}"RESULT = "${NC} && ./$(EXEC)
	@ printf "\n"
clean:
	@ $(RM) $(OBJ_DIR) main

fclean: clean
	@ $(RM) library/$(NAME)
	@ echo ${COLOR}"Libft Library and objs CLEAN DONE"${NC}

re: fclean all

.PHONY: all clean fclean re