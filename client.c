/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 21:13:23 by ztouzri           #+#    #+#             */
/*   Updated: 2021/06/12 19:12:24 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_wait = 1;

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

void	charTobintab(char c, int pid)
{
	int	i;

	i = 0;
	g_wait = 1;
	while (i < 8)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i++;
		while (g_wait)
		{
		}
		g_wait = 1;
		usleep(130);
	}
}

void	next(int sig)
{
	(void)sig;
	g_wait = 0;
}

int	main(int ac, char **av)
{
	pid_t	servpid;
	int		i;

	if (ac == 3)
	{
		if (!isvalidnum(av[1]))
		{
			ft_putstr("Invalid PID\n");
			return (0);
		}
		signal(SIGUSR1, next);
		servpid = ft_atoi(av[1]);
		i = 0;
		while (av[2][i])
		{
			charTobintab(av[2][i], servpid);
			i++;
		}
		charTobintab(0, servpid);
		ft_putstr("Message Delivered\n");
	}
	else
		ft_putstr("Usage: ./client PID_SERVER MESSAGE\n");
	return (0);
}
