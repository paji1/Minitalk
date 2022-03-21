/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 03:51:20 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/03/18 05:09:28 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"


void sigaction_hand(int sig,siginfo_t *info,void *data)
{
	static char c;
	static int pkey;
	static int spid;

	
	if (info->si_pid != spid)
		pkey = 0;
	if (!pkey)
	{
		if (!c)
			c = recieve_byte(sig,info);
		if(c)
		{
			pkey = generate_key() % 10 + 1;
			send_crypted_key(7,pkey,info->si_pid);
			spid = info->si_pid;
			pkey = receive_crypted_key(pkey,c);
			// ft_putnbr_fd(info->si_pid,1),write(1," ",1);
			return ;
		}
		
	}
	else
	{
		c = recieve_byte(sig,info);
		if (c)
		{
			c += pkey;
			write(1,&c,1);
			c = 0;
		}
	}
}

int main(int ac, char **av)
{
	struct sigaction clsa;
	sigaddset(&clsa.sa_mask,SIGABRT);
	clsa.sa_flags = SA_SIGINFO;
	
	clsa.sa_sigaction = &sigaction_hand;
	sigaction(SIGUSR1, &clsa , NULL);
	sigaction(SIGUSR2, &clsa , NULL);
	sigaction(SIGABRT, &clsa , NULL);

	write(1, "\nPID=", 5);
	ft_putnbr_fd(getpid(),1);
	write(1, "\n",1);
	while (1)
		pause();
	return (0);
}