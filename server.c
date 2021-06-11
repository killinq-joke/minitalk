/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 21:14:32 by ztouzri           #+#    #+#             */
/*   Updated: 2021/06/11 09:35:53 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	ft_put(int signum)
{
	printf("salut %d\n", signum);
}

int main()
{
	pid_t		pid;
	// sigset_t	*set;

	// sigemptyset(set);
	// sigaddset(set, SIGUSR1);
	signal(SIGUSR1, ft_put);
	pid = getpid();
	ft_putstr("LISTENING ON PID: ");
	ft_putnbr(pid);
	ft_putstr("\n");
	while (1)
	{

	}
	return (0);
}
