/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 21:13:30 by jijoo             #+#    #+#             */
/*   Updated: 2022/05/19 20:45:27 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*res;
	int		idx;
	int		j;

	j = 0;
	len = 1 + ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(len);
	if (res == 0)
		return (0);
	idx = 0;
	while (s1[idx])
	{
		res[idx] = s1[idx];
		idx++;
	}
	while (s2[j])
	{
		res[idx] = s2[j];
		j++;
		idx++;
	}
	res[idx] = 0;
	return (res);
}
