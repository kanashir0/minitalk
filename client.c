/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasuhir <gyasuhir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:57:04 by gyasuhir          #+#    #+#             */
/*   Updated: 2025/03/16 13:23:49 by gyasuhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ack = 0;

void	set_ack(int signum)
{
	if (signum == SIGUSR1)
		ack = 1;
}

void	send_char(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR2); // case 1
		else
			kill(pid, SIGUSR1); // case 0
		bit++;
		while (!ack);
		ack = 0;
	}
	return ;
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		signal(SIGUSR1, set_ack);
		ft_printf("Registered server PID: %d\n", pid);
		while (*argv[2])
		{
			send_char(pid, *argv[2]);
			argv[2]++;
		}
		send_char(pid, 0);
	}
	else
		ft_printf("Wrong number of parameters! Expected: ./client [PID] [Message]");
	return (0);
}