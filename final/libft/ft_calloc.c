/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:58:33 by jijoo             #+#    #+#             */
/*   Updated: 2022/05/21 00:50:36 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;

	if (nmemb >= 2147483647 || size >= 2147483647)
		return (0);
	ret = malloc(nmemb * size);
	if (ret == 0)
		return (0);
	ft_bzero(ret, (nmemb * size));
	return (ret);
}
