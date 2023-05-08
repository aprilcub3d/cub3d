/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:06:13 by jijoo             #+#    #+#             */
/*   Updated: 2022/05/19 20:56:35 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{	
	int		idx;
	char	*new;

	new = (char *)s;
	idx = 0;
	while (s[idx])
		idx++;
	while (idx >= 0)
	{
		if (s[idx] == (char)c)
			return (new + idx);
		idx--;
	}
	return (0);
}
