/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:16:50 by jijoo             #+#    #+#             */
/*   Updated: 2022/05/20 22:48:22 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*new;
	const unsigned char	uc = (unsigned char)c;

	new = (unsigned char *)s;
	while (n--)
	{
		if (uc == *new)
			return ((void *)new);
		new++;
	}
	return (0);
}
