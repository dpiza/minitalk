/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:27:58 by dpiza             #+#    #+#             */
/*   Updated: 2021/11/03 02:18:34 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_signal(int pid, char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i = 8;
		while (i-- > 0)
		{
			if (*str & 1 << i)
				kill (pid, SIGUSR1);
			else
				kill (pid, SIGUSR2);
			usleep(100);
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc < 3)
		return (0);
	send_signal(ft_atoi(argv[1]), argv[2]);
	return (0);
}
