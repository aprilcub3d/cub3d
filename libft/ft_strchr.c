/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 22:31:43 by jijoo             #+#    #+#             */
/*   Updated: 2022/05/19 20:55:24 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*new;

	new = (char *)s;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (new + i);
		i++;
	}
	if (c == 0)
		return (new + i);
	return (0);
}
