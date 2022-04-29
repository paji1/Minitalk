/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 03:40:32 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/04/29 23:13:12 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

int	g_private_key;

void	sigaction_hand(int sig)
{
	int	c;

	if (!g_private_key)
	{
		c = recieve_byte(sig, NULL);
		if (c)
			g_private_key = c;
	}
}

int	main(int ac, char **av)
{
	int					key ;
	struct sigaction	clsa;
	int					serv_pid;

	serv_pid = check_pid_ac(av, ac);
	key = generate_key() % 10 + 1;
	clsa.sa_handler = &sigaction_hand;
	sigaction(SIGUSR1, &clsa, NULL);
	sigaction(SIGUSR2, &clsa, NULL);
	if (!send_crypted_key(7, key, serv_pid))
		return (write(1, "error not sent", 15), 1);
	while (!g_private_key)
		pause();
	if (g_private_key)
	{
		g_private_key *= key;
		usleep(700);
		while (*av[2])
		{
			*av[2] -= g_private_key;
			send_byte(*(av[2])++, serv_pid);
		}
		write(1, "message sent to server\n", 23);
	}
	return (0);
}
