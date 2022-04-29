/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 04:02:47 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/04/29 23:24:11 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define PUBLIC_KEY 53;

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/include/libft.h"
# include <stdio.h>
# include <math.h>

typedef struct unicode
{
	char		*s;
	int			pkey;
	int			sig;
	int			spid;
	siginfo_t	*info;
}	t_unicode;

int		send_crypted_key(int public_key, int key, pid_t pid_to);
int		receive_crypted_key(int private_key, int receive_key);
int		send_byte(char byte, pid_t pid);
int		recieve_byte(int sig, siginfo_t *info);
int		get_key(int sig, siginfo_t *info);
int		check_pid_ac(char **s, int ac);
int		generate_key(void);
void	sr_pkey(int *pkey, char *c, t_unicode *u, int *spid);
#endif