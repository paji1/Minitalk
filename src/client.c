/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 03:40:32 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/04/29 19:48:00 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"
int private_key;
void sigaction_hand(int sig)
{
	int c;
	if (!private_key)
	{
		c = recieve_byte(sig,NULL);
		if (c)
			private_key = c;
	}
}

int main(int ac, char **av)
{
	int					key ;
	struct	sigaction	clsa;
	int					serv_pid;
	
	key = generate_key() % 10 + 1;
	clsa.sa_handler = &sigaction_hand;
	sigaction(SIGUSR1, &clsa , NULL);
	sigaction(SIGUSR2, &clsa , NULL);
	serv_pid = atoi(av[1]);
	if (!send_crypted_key(7,key ,serv_pid))
		return write(1,"error not sent",15),1;
	while(!private_key)
		pause();
	if (private_key)
	{
		private_key *= key;
		usleep(700);
		while (*av[2])
		{
			*av[2] -= private_key;  
			send_byte(*(av[2])++,serv_pid);
		}
		write(1,"message sent to server\n",23);
	}
	return 0;
}