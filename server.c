/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasuhir <gyasuhir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:57:09 by gyasuhir          #+#    #+#             */
/*   Updated: 2025/03/02 13:09:52 by gyasuhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
//TODO: change printf to ft_printf

int	main(void)
{
	printf("Server have started with PID: %d\n", getpid());
	return (0);
}