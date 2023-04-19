/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:15:51 by jijoo             #+#    #+#             */
/*   Updated: 2022/05/19 20:47:29 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	idx;
	char	*new;

	new = (char *)s;
	idx = 0;
	while (idx < n)
	{
		*(new + idx) = (char)c;
		idx++;
	}
	return (s);
}
