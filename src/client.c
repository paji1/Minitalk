/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 03:40:32 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/03/12 10:54:24 by tel-mouh         ###   ########.fr       */
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
	int key ;
	
	key = generate_key() % 10 + 1;




	struct sigaction clsa;
	clsa.sa_handler = &sigaction_hand;
	sigaction(SIGUSR1, &clsa , NULL);
	sigaction(SIGUSR2, &clsa , NULL);

	// write(1,&av[2],4);
	if (!send_crypted_key(7,key ,atoi(av[1])))
		return 1;
	while(!private_key)
		pause();
	if (private_key)
	{
		private_key *= key;
		// return 0;
	}
	// ft_putnbr_fd(private_key, 1);
	// ft_putchar_fd('\n',1);
	if (private_key)
	{
		
		usleep(800);
		while (*av[2])
		{
			*av[2] -= private_key;  
			send_byte(*(av[2])++,atoi(av[1]));
		}
	}
	// if (private_key)

	// send_byte(*av[2]++, atoi(av[1]));

	// state = 0;
	// if (!state)
	// {
	// 	struct sigaction clsa;
	// 	clsa.sa_flags = SA_SIGINFO;
	// 	clsa.sa_sigaction = &sigaction_hand;
	// 	sigaction(SIGUSR1, &clsa , NULL);
	// }
	// double i = 4;
	// char c;
	// while (i >= 0)
	// {
	// 	c = (pid / (int)pow((double)10, i)) % 10 + '0';
	
	// 	write (1,&c,1);
	// 	i--;
	// }

	
	return 0;
}