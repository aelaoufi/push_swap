/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:17:30 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/05/20 15:36:40 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_bzero(void *dst, size_t n)
{
	int	i;

	i = 0;
	while ((size_t)i < n)
	{
		((char *)dst)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	str = malloc(count * size);
	if (str == NULL)
		return (0);
	ft_bzero(str, count * size);
	return (str);
}

static int	ft_nmbofwrds(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] == c && str[i])
		i++;
	while (str[i])
	{
		if (str[i] == c && str[i - 1] != c)
			count++;
		i++;
	}
	if (str[ft_strlen(str) - 1] != c && str[0] != '\0')
		count++;
	return (count);
}

static char	**wordsplit(const char *s, char c, char **str, int i)
{
	int	end;
	int	j;
	int	k;

	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			end = i;
			while (s[end] != c && s[end])
				end++;
			str[j] = (char *)ft_calloc(sizeof(char), end - i + 1);
			if (str[j] == NULL)
				return (NULL);
			k = 0;
			while (i < end)
				str[j][k++] = s[i++];
			j++;
		}
		if (s[i])
			i++;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	str = (char **)ft_calloc(sizeof(char *), ft_nmbofwrds((char *)s, c) + 1);
	if (str == NULL)
		return (NULL);
	str = wordsplit(s, c, str, i);
	return (str);
}
