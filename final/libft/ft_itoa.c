/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 23:43:59 by jijoo             #+#    #+#             */
/*   Updated: 2022/05/20 16:07:17 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n);

void	ft_div(int num, int p, char *str)
{
	int		rest;

	if (num < 0)
		num *= -1;
	if (p == 1)
	{
		rest = num % 10;
		*str = rest + '0';
	}
	else
	{
		num /= 10;
		ft_div(num, p - 1, str);
	}
}

int	get_power(int *num, int *l)
{
	int	p;
	int	cp;

	cp = *num;
	p = 1;
	*l = 1;
	if (cp < 0)
	{
		(*l) += 1;
		cp *= -1;
	}
	while (cp > 9)
	{
		cp /= 10;
		p++;
	}
	*l += p;
	return (p);
}

char	*ex_itoa(void)
{
	char	*res;

	res = ft_itoa(-2147483647);
	res[10] = '8';
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		power;
	int		len;

	if (n == -2147483648)
		return (ex_itoa());
	power = get_power(&n, &len);
	res = (char *)malloc(len);
	if (res == 0)
		return (0);
	if (n < 0)
	{
		*res = '-';
		res++;
	}
	while (power)
	{
		ft_div(n, power, res);
		res++;
		power--;
	}
	*res = 0;
	return (res - (len - 1));
}
