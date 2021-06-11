/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 21:14:32 by ztouzri           #+#    #+#             */
/*   Updated: 2021/06/11 14:20:17y ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	ft_sigclient(int sig, siginfo_t pid, void *context)
{
	(void)context;
	kill(pid.si_pid, sig);
}

void	ft_put(int signum, siginfo_t *pid, void *context)
{
	static	int				i = 0;
	static	unsigned char	c = 0;
	int						bin;

	(void)context;
	if (signum == SIGUSR2)
		bin = 1;
	else
		bin = 0;
	c |= bin << i++;
	if (i > 7)
	{
		if (c == 0)
			ft_putchar('\n');
		ft_putchar(c);
		i = 0;
		c = 0;
	}
	kill(pid->si_pid, SIGUSR1);
}

int main()
{
	pid_t		pid;
	struct		sigaction sa;


	pid = getpid();
	ft_putstr("LISTENING ON PID: ");
	ft_putnbr(pid);
	ft_putstr("\n");
	sa.sa_sigaction = ft_put;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
