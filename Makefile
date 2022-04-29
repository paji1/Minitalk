# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/06 02:57:56 by tel-mouh          #+#    #+#              #
#    Updated: 2022/04/27 17:24:12 by tel-mouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #




# ###################COMMAND#############################
CC=cc
CFLAGS= -g
RM = rm -f
AR    := ar rcs
# ###################PATH#############################
SRC_DIR = src
INCLUDE_DIR = include


SRCS_SE = crypt.c  send_recieve.c  server.c
SRCS_CL = crypt.c  send_recieve.c  client.c check_pid.c
OBJS_SE = $(addprefix obj/, $(SRCS_SE:.c=.o))
OBJS_CL = $(addprefix obj/, $(SRCS_CL:.c=.o))
INCLUDES = $(INCLUDE_DIR)/Minitalk.h
SERVER = bin/server
CLIENT = bin/client
M ?= "taha"

# ################LIBFT##############################

LIBFT = libft/library/libft.a

# ################COLOR##############################
COLOR='\033[0;32m'
NC='\033[0m' # No Color
RE= '\033[0;34m'
RED='\033[0;31m'
# ###################################################
all: $(LIBFT) $(SERVER) $(CLIENT)


$(SERVER) : $(OBJS_SE) $(LIBFT)
	@ echo "Create "${RED}"SERVER"${NC}
	@ $(CC) $(CFLAGS) $(OBJS_SE) $(LIBFT) -o $(SERVER)

$(CLIENT) : $(OBJS_CL) $(LIBFT)	
	@ echo "Create "${RED}"CLIENT"${NC}
	@ $(CC) $(CFLAGS) $(OBJS_CL) $(LIBFT) -o $(CLIENT)

$(LIBFT) :
	@ make -C libft
kill:
	@ ./scripts/killprocess.sh
run:
	@ ./scripts/script_pid.sh $(M)
obj/%.o: src/%.c $(INCLUDES)
	@ echo ${RE}"Making the $(notdir $@)"${NC}
	@ $(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

clean : $(OBJS_SE) $(OBJS_CL)
	@ rm -rf $(OBJS_SE) $(OBJS_CL)
	
fclean : clean
	@ rm -rf $(CLIENT) $(SERVER)
	@ make fclean -C libft 
	
re: fclean
	@ make all
	@ make kill