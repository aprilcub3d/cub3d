/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 23:07:23 by jijoo             #+#    #+#             */
/*   Updated: 2022/05/21 01:14:42 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	in(char ch, char *set)
{
	while (*set)
	{
		if (ch == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ex(void)
{
	char	*res;

	res = (char *)malloc(1);
	*res = 0;
	return (res);
}

void	my_strlcpy(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = *(src + i);
		i++;
	}
	dest[i] = 0;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		idx;
	int		idx2;
	char	*res;

	idx = 0;
	idx2 = 0;
	while (s1[idx2])
		idx2++;
	idx2--;
	while (s1[idx] && in(s1[idx], (char *)set))
		idx++;
	while (in(s1[idx2], (char *)set) && idx2)
		idx2--;
	if (idx > idx2)
		return (ex());
	res = (char *)malloc(idx2 - idx + 2);
	if (res == 0)
		return (0);
	my_strlcpy(res, (char *)s1 + idx, idx2 - idx + 1);
	return (res);
}
