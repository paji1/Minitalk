/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 04:02:47 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/03/12 10:39:56 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libft/include/libft.h"
#include <stdio.h>
#include <math.h>
int send_crypted_key(int public_key,int key, pid_t pid_to);
int receive_crypted_key(int private_key,int receive_key);
int send_byte(char byte, pid_t pid);
int recieve_byte(int sig,siginfo_t *info);
int get_key(int sig,siginfo_t *info);
#define PUBLIC_KEY 53;
int generate_key();
