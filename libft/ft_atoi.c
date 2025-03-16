/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasuhir <gyasuhir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:28:17 by gyasuhir          #+#    #+#             */
/*   Updated: 2024/10/27 10:31:05 by gyasuhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_set_signal(char *n, int *negative)
{
	while ((*n >= 9 && *n <= 13) || *n == ' ')
		n++;
	if (*n == '+')
	{
		n++;
		return (n);
	}
	if (*n == '-')
	{
		*negative *= -1;
		n++;
	}
	return (n);
}

int	ft_atoi(const char *nptr)
{
	int		negative;
	int		result;
	char	*n;

	negative = 1;
	n = (char *) nptr;
	result = 0;
	n = ft_set_signal(n, &negative);
	while (*n)
	{
		if (*n >= '0' && *n <= '9')
			result = (result * 10) + (*n - '0');
		else
			return (result * negative);
		n++;
	}
	return (result * negative);
}
