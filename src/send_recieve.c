/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_recieve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 01:39:16 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/03/18 05:01:01 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

int send_byte(char byte, pid_t pid)
{
	int i;
	int check;
	
	i = -1;
	check = 0;
	while (++i < 8)
	{
		if (((byte >> (7 - i)) & 1) == 1)
		{
			check = kill(pid, SIGUSR1);
			// write(1,"1",1);
			// usleep(800);
		}
		else
			check = kill(pid, SIGUSR2);

			usleep(700);
		if (check == -1)
			return (0);
	}
	
	// usleep(1000);
	return (1);
}

int recieve_byte(int sig,siginfo_t *info)
{
	static int a;
	static int i;
	int			t;
	static pid_t pid;
	
	
	if (info)
	{
		if (pid && pid != info->si_pid)
		{
			a = 0;
			i = 8;
		}
		pid = info->si_pid;
	}
		
	if (i <= 0)
		i = 8;
	if (sig == SIGUSR1)
		a =  (a  | (1 << (i - 1)));
	if (i == 1)
		return  (t = a, a = 0, i--, t);
	return (i--, 0);
}
