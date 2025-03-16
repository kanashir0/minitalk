/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasuhir <gyasuhir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:57:09 by gyasuhir          #+#    #+#             */
/*   Updated: 2025/03/16 12:14:52 by gyasuhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int		bit = 0;
	static char	c_buffer = 0;

	(void)context;
	if (signum == SIGUSR1)
		c_buffer &= ~(1 << bit);
	else if (signum == SIGUSR2)
		c_buffer |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c_buffer);
		if (c_buffer == '\0')
			ft_printf("\n");
		bit = 0;
		c_buffer = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	
	ft_printf("Server have started with PID: %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}