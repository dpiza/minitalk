/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:55:31 by dpiza             #+#    #+#             */
/*   Updated: 2021/11/04 03:33:10 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	signal_handler(int signum, siginfo_t *info, void *ucontext)
{
	static unsigned char	c;
	static int				i;

	(void)ucontext;
	if (signum == SIGUSR1)
		c = c << 1 | 1;
	else
		c = c << 1 | 0;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		if (!c)
			write(1, "\n", 2);
		i = 0;
		c = 0;
	}
	kill (info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	act;

	ft_printf("PID: %d\n", getpid());
	act.sa_sigaction = signal_handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
