/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 21:13:23 by ztouzri           #+#    #+#             */
/*   Updated: 2021/06/11 09:33:56 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	isvalidnum(char *pidstr)
{
	int	i;

	i = 0;
	while (pidstr[i])
	{
		if (!ft_isdigit(pidstr[i]))
			return (0);
		i++;
	}
	return (1);
}

#include <stdio.h>
int main(int ac, char **av)
{
	pid_t	pid;
	if (ac == 3)
	{
		if (!isvalidnum(av[1]))
		{
			ft_putstr("Error\n");
			return (0);
		}
		pid = ft_atoi(av[1]);
		printf("%d\n", kill(pid, SIGUSR1));

	}
	return (0);
}
