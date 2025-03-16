/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasuhir <gyasuhir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 10:35:37 by gyasuhir          #+#    #+#             */
/*   Updated: 2024/11/02 11:50:44 by gyasuhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*cdest;
	unsigned char	*csrc;

	if (src == dest)
		return (dest);
	cdest = (unsigned char *) dest;
	csrc = (unsigned char *) src;
	if (dest <= src)
	{
		while (n-- > 0)
			*cdest++ = *csrc++;
	}
	else if (dest > src)
	{
		cdest += n - 1;
		csrc += n - 1;
		while (n-- > 0)
			*cdest-- = *csrc--;
	}
	return (dest);
}
