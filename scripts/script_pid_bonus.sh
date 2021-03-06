#!/bin/bash
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    script_pid.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 02:07:24 by tel-mouh          #+#    #+#              #
#    Updated: 2022/03/09 09:22:57 by tel-mouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


PID=$(ps aux | grep /server_bonus$ | awk 'NR==1 {print $2}')

if [ -z ${PID} ]
	then
		./bin/server_bonus > /dev/ttys001 &
		sleep 0.5
		PID=$(ps aux | grep /server_bonus$ | awk 'NR==1 {print $2}')
		./bin/client_bonus $PID "$*"
else 
	./bin/client_bonus $PID "$*"
fi