/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:29:19 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/04/29 23:19:07 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Minitalk.h"

int	check_pid_ac(char **s, int ac)
{
	int	i;

	i = -1;
	if (ac != 3)
	{
		write(2, "invalid arguments", 18);
		exit(EXIT_FAILURE);
	}
	while (s[1][++i])
	{
		if (!ft_isdigit(s[1][i]))
		{
			write(2, "invalid pid", 12);
			exit(EXIT_FAILURE);
		}
	}
	return (ft_atoi(s[1]));
}
