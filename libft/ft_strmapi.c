/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 23:50:37 by jijoo             #+#    #+#             */
/*   Updated: 2022/05/19 20:45:49 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		len;
	int		idx;

	len = 0;
	while (s[len])
		len++;
	res = (char *)malloc(len + 1);
	if (res == 0)
		return (0);
	idx = 0;
	while (idx < len)
	{
		res[idx] = f((unsigned int)idx, s[idx]);
		idx++;
	}
	res[idx] = 0;
	return (res);
}
