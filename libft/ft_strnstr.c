/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:26:58 by jijoo             #+#    #+#             */
/*   Updated: 2022/05/21 00:46:21 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find(const char *s1, const char *s2)
{
	size_t	idx;

	idx = 0;
	while (s2[idx])
	{
		if (s1[idx] != s2[idx])
			return (0);
		idx++;
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	ni_len;
	size_t	idx;

	ni_len = ft_strlen(little);
	if (!ni_len)
		return ((char *)big);
	if (len == 0)
		return (0);
	idx = 0;
	while (big[idx] && (len - ni_len + 1) > 0)
	{
		if (find(big, little))
			return ((char *)big);
		big++;
		len--;
	}
	return (0);
}
