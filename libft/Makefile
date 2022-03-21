# # *****************************************************************
# CC        := cc
# CFLAGS    := -Wall -Wextra -Werror

# # *****************************************************************
# RM    := rm -f
# AR    := ar rcs
# # *****************************************************************
# HEADER := libft.h
# # *****************************************************************
# NAME    := libft.a
# SRCS    := ft_calloc.c ft_isdigit.c ft_memchr.c ft_memset.c ft_putstr_fd.c ft_striteri.c ft_strlen.c ft_strrchr.c\
# ft_toupper.c ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putchar_fd.c ft_split.c ft_strjoin.c ft_strmapi.c ft_strtrim.c\
# ft_atoi.c ft_isalpha.c ft_itoa.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c ft_strlcat.c ft_strncmp.c ft_substr.c\
# ft_bzero.c ft_isascii.c ft_memmove.c ft_putnbr_fd.c ft_strdup.c ft_strlcpy.c ft_strnstr.c ft_tolower.c

# OBJS    := $(SRCS:.c=.o)
# OBJS_bonus    := $(SRCS_bonus:.c=.o)

# # *****************************************************************
# all:    $(NAME)

# $(NAME):	$(OBJS)  
# 	$(AR) $(NAME) $(OBJS)



# %.o: %.c
# 	$(CC) $(CFLAGS) -o $@ -c $<

# clean:
# 	$(RM) $(OBJS) $(OBJS_bonus) $(OUTPUT)

# fclean:	clean
# 		$(RM) $(NAME)

# re:	fclean all

# .PHONY:	all clean fclean re

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