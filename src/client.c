/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:27:58 by dpiza             #+#    #+#             */
/*   Updated: 2021/11/04 03:31:07 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	g_ack;

void	acknowledge(int signum)
{
	(void)signum;
	g_ack = 1;
}

void	send_signal(int pid, char *str)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(str) + 1;
	while (len--)
	{
		i = 8;
		while (i-- > 0)
		{
			g_ack = 0;
			if (*str & 1 << i)
				kill (pid, SIGUSR1);
			else
				kill (pid, SIGUSR2);
			signal(SIGUSR1, acknowledge);
			while (!g_ack)
				pause();
			usleep(100);
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc < 3)
	{
		ft_printf("Usage: ./client [SRV_PID] [STRING]\n");
		return (EXIT_FAILURE);
	}
	send_signal(ft_atoi(argv[1]), argv[2]);
	return (0);
}
