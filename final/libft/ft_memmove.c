/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 21:49:53 by jijoo             #+#    #+#             */
/*   Updated: 2022/05/20 16:21:30 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (s > d)
	{
		i = 0;
		while (n--)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (s < d)
	{
		i = n - 1;
		while (n--)
		{
			d[i] = s[i];
			i--;
		}
	}
	return (dest);
}
