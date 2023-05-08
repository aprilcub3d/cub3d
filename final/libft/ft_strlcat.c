/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 22:31:22 by jijoo             #+#    #+#             */
/*   Updated: 2023/04/20 17:26:03 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;

	len_dest = 0;
	len_src = 0;
	while (dest[len_dest])
		len_dest++;
	while (src[len_src])
		len_src++;
	i = 0;
	if (size <= len_dest)
		return (size + len_src);
	if (size > len_dest + 1)
	{
		while (src[i] && (i < size - len_dest - 1))
		{
			dest[len_dest + i] = src[i];
			i++;
		}
	}
	dest[len_dest + i] = 0;
	return (len_dest + len_src);
}

size_t	ft_strcat(char *dest, const char *src)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;

	len_dest = 0;
	len_src = 0;
	while (dest[len_dest])
		len_dest++;
	while (src[len_src])
		len_src++;
	i = 0;
	while (src[i])
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = 0;
	return (len_dest + len_src);
}
