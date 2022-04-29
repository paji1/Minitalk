/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crypt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:51:57 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/04/29 21:16:54 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Minitalk.h"

int generate_key()
{
	int pid;

	pid = getpid();
	return (((pid % 7) * (pid % 10)) + 1);
}

int  send_crypted_key(int public_key,int key, pid_t pid_to)
{
	if (!send_byte(((key * public_key)), pid_to))
		return (0);
	return (1);
}

int receive_crypted_key(int private_key,int receive_key)
{
	return (private_key * receive_key);
}

void sr_pkey(int *pkey,char *c,unicode *u,int *spid)
{
	if (!*c)
		*c = recieve_byte(u->sig,u->info);
	if(*c)
	{
		*pkey = generate_key() % 10 + 1;
		send_crypted_key(7,*pkey, u->info->si_pid);
		*spid = u->info->si_pid;
		*pkey = receive_crypted_key(*pkey,*c);
	}
}