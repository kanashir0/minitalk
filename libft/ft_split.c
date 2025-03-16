/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasuhir <gyasuhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:12:04 by gyasuhir          #+#    #+#             */
/*   Updated: 2024/10/28 17:58:03 by gyasuhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static int	ft_get_next_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	*ft_get_next_word(char const *s, char c)
{
	char	*str;
	int		len;

	len = ft_get_next_len(s, c);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s, len + 1);
	return (str);
}

static int	ft_count_word(char const *s, char c)
{
	int	wc;
	int	i;

	wc = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			wc += 1;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (wc);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;

	if (s == NULL)
		return (NULL);
	arr = (char **) malloc((ft_count_word(s, c) + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			arr[i] = ft_get_next_word(s, c);
			if (arr[i] == NULL)
				return (ft_free_arr(arr));
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	arr[i] = NULL;
	return (arr);
}
