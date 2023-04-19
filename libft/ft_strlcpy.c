/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 22:31:17 by jijoo             #+#    #+#             */
/*   Updated: 2022/05/19 20:40:49 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	size_src;
	size_t	i;

	size_src = 0;
	while (src[size_src])
		size_src++;
	if (size == 0)
		return (size_src);
	i = 0;
	while (i < size - 1 && i < size_src)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (size_src);
}
