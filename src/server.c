/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 03:51:20 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/04/29 21:22:56 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

int	get_unicount_count(char c)
{
	int	i;

	i = 7;
	while (c >> i & 1)
		i--;
	return (7 - i);
}

void	print_unicode(char *s, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		write(1, &s[i], 1);
}

void	get_uc(char *c, int *co, int *i, unicode *u)
{
	*c = recieve_byte(u->sig, u->info);
	if (*c)
	{
		*c += (u->pkey);
		if (!(*c >> 7 & 1))
			write(1, &c[0], 1);
		else
		{
			if (!*i)
				*co = get_unicount_count(*c);
			if (*i == *co - 1)
			{
				(u->s)[*i] = *c;
				print_unicode(u->s, *co);
				*i = 0;
			}
			else
			{
				(u->s)[*i] = *c;
				*i += 1;
			}
		}
		*c = 0;
	}
}

void	sigaction_hand(int sig, siginfo_t *info, void *data)
{
	static char		c;
	static int		count;
	static int		i;
	static char		unic[4];
	static unicode	u;

	u.sig = sig;
	u.info = info;
	u.s = unic;
	if (info->si_pid != u.spid)
	{
		(u.pkey) = 0;
		ft_bzero(u.s, 4 * 4);
	}
	if (!u.pkey)
		sr_pkey((&(u.pkey)), &c, &u, &(u.spid));
	else
		get_uc(&c, &count, &i, &u);
}

int	main(int ac, char **av)
{
	struct sigaction	clsa;

	sigaddset(&clsa. sa_mask, SIGABRT);
	clsa.sa_flags = SA_SIGINFO;
	clsa.sa_sigaction = &sigaction_hand;
	sigaction(SIGUSR1, &clsa, NULL);
	sigaction(SIGUSR2, &clsa, NULL);
	write(1, "\nPID=", 5);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
