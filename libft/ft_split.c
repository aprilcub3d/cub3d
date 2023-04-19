/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:03:04 by jijoo             #+#    #+#             */
/*   Updated: 2022/07/08 21:05:52 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_rl(char *str, char crt)
{
	int	rl;
	int	i;

	rl = 0;
	i = 0;
	while (str[i])
	{
		if (i > 0 && str[i] != crt && str[i - 1] == crt)
			rl++;
		else if (i == 0 && str[i] != crt)
			rl++;
		i++;
	}
	return (rl);
}

size_t	get_sl(char **dp, char crt)
{
	size_t	sl;

	sl = 0;
	while (**dp == crt)
		*dp += 1;
	while (**dp && **dp != crt)
	{
		*dp += 1;
		sl++;
	}
	return (sl);
}

void	split_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}

void	dobby(char **s, int i)
{
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	res_len;
	size_t	idx;
	char	*new;
	size_t	str_len;

	new = (char *)s;
	res_len = get_rl(new, c);
	res = (char **)malloc(sizeof(char *) * (res_len + 1));
	if (res == 0)
		return (0);
	idx = 0;
	while (idx < res_len)
	{
		str_len = get_sl(&new, c);
		res[idx] = (char *)malloc(str_len + 1);
		if (res[idx] == 0)
		{
			dobby(res, idx);
			return (0);
		}
		split_strlcpy(res[idx++], new - str_len, str_len);
	}
	res[idx] = 0;
	return (res);
}
