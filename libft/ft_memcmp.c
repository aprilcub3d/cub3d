/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:43:26 by jijoo             #+#    #+#             */
/*   Updated: 2022/05/20 17:07:26 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*n1;
	unsigned char	*n2;
	size_t			idx;

	n1 = (unsigned char *)s1;
	n2 = (unsigned char *)s2;
	idx = 0;
	if (n == 0)
		return (0);
	while (idx < n - 1 && (n1[idx] == n2[idx]))
		idx++;
	return (n1[idx] - n2[idx]);
}
