/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:55:31 by dpiza             #+#    #+#             */
/*   Updated: 2021/11/03 23:43:29 by dpiza            ###   ########.fr       */
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
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
	kill (info->si_pid, SIGUSR1);
	info->si_pid = 0;
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
