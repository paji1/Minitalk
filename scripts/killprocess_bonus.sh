#!/bin/bash
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    killprocess.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 06:27:06 by tel-mouh          #+#    #+#              #
#    Updated: 2022/03/09 06:29:44 by tel-mouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PID=$(ps aux | grep /server_bonus$ | awk 'NR==1 {print $2}')

while [ ! -z ${PID} ]
do
	PID=$(ps aux | grep /server_bonus$ | awk 'NR==1 {print $2}')
	if [ ! -z ${PID} ]
	then
		KILL $PID
	fi
done
