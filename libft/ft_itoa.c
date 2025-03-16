/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasuhir <gyasuhir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:29:52 by gyasuhir          #+#    #+#             */
/*   Updated: 2024/10/27 10:30:47 by gyasuhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_abs(long num)
{
	if (num < 0)
		return (-num);
	return (num);
}

static char	ft_get_next_char(long *num)
{
	char	c;

	c = '0';
	if (*num == 0)
		return (c);
	if (*num != 0)
	{
		c = (ft_abs(*num) % 10) + '0';
		*num = *num / 10;
	}
	return (c);
}

static int	ft_get_num_len(long num)
{
	int	len;

	len = 0;
	if (num <= 0)
		len++;
	while (num != 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*res;
	long	num;

	num = n;
	len = ft_get_num_len(num);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	if (num < 0)
		res[0] = '-';
	if (num == 0)
		res[0] = '0';
	len--;
	while (len >= 0 && num != 0)
	{
		res[len] = ft_get_next_char(&num);
		len--;
	}
	if (len == 1)
		res[0] = '-';
	return (res);
}
