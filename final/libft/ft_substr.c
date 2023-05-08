/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:30:28 by jijoo             #+#    #+#             */
/*   Updated: 2022/05/21 01:01:22 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*res;
	long unsigned int	idx;

	if (start >= ft_strlen(s))
	{
		res = (char *)malloc(1);
		if (res == 0)
			return (0);
		*res = 0;
		return (res);
	}
	if (len <= ft_strlen(s))
		res = (char *)malloc(len + 1);
	else
		res = (char *)malloc(ft_strlen(s) + 1);
	if (res == 0)
		return (0);
	idx = 0;
	while (idx < len && s[start + idx])
	{
		res[idx] = s[start + idx];
		idx++;
	}
	res[idx] = 0;
	return (res);
}
