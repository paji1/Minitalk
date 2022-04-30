# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/06 02:57:56 by tel-mouh          #+#    #+#              #
#    Updated: 2022/04/30 00:17:59 by tel-mouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #




# ###################COMMAND#############################
CC=cc
CFLAGS= -g -Wall -Wextra -Werror
RM = rm -f
AR    := ar rcs
# ###################PATH#############################
SRC_DIR = src
INCLUDE_DIR = include


SRCS_SE_bonus = crypt.c  send_recieve.c  server_bonus.c
SRCS_CL_bonus = crypt.c  send_recieve.c  client_bonus.c check_pid.c
OBJS_CL_bonus = $(addprefix obj/, $(SRCS_CL_bonus:.c=.o))
OBJS_SE_bonus = $(addprefix obj/, $(SRCS_SE_bonus:.c=.o))
SRCS_SE = crypt.c  send_recieve.c  server.c
SRCS_CL = crypt.c  send_recieve.c  client.c check_pid.c
OBJS_SE = $(addprefix obj/, $(SRCS_SE:.c=.o))
OBJS_CL = $(addprefix obj/, $(SRCS_CL:.c=.o))
INCLUDES = $(INCLUDE_DIR)/Minitalk.h
SERVER = bin/server
CLIENT = bin/client
SERVER_BONUS = bin/server_bonus
CLIENT_BONUS= bin/client_bonus
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

$(SERVER_BONUS) : $(OBJS_SE_bonus) $(LIBFT)
	@ echo "Create "${RED}"SERVER_BONUS"${NC}
	@ $(CC) $(CFLAGS) $(OBJS_SE_bonus) $(LIBFT) -o $(SERVER_BONUS)

$(CLIENT) : $(OBJS_CL) $(LIBFT)	
	@ echo "Create "${RED}"CLIENT"${NC}
	@ $(CC) $(CFLAGS) $(OBJS_CL) $(LIBFT) -o $(CLIENT)
	
$(CLIENT_BONUS) : $(OBJS_CL_bonus) $(LIBFT)	
	@ echo "Create "${RED}"CLIENT_BONUS"${NC}
	@ $(CC) $(CFLAGS) $(OBJS_CL_bonus) $(LIBFT) -o $(CLIENT_BONUS)

bonus: $(LIBFT) $(SERVER_BONUS) $(CLIENT_BONUS)
	
	
$(LIBFT) :
	@ make -C libft
kill:
	@ ./scripts/killprocess.sh
kill_bonus:
	@ ./scripts/killprocess_bonus.sh
run:
	@ ./scripts/script_pid.sh $(M)
run_bonus:
	@ ./scripts/script_pid_bonus.sh $(M)
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