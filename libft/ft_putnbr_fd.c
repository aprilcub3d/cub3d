/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:44:07 by jijoo             #+#    #+#             */
/*   Updated: 2022/05/20 18:52:36 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_div(int num, int p, int f)
{
	int		rest;
	char	c;

	if (p == 1)
	{
		rest = num % 10;
		c = rest + '0';
		write(f, &c, 1);
	}
	else
	{
		num /= 10;
		put_div(num, p - 1, f);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int	power;
	int	cp;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	cp = n;
	power = 1;
	while (cp > 9)
	{
		cp /= 10;
		power++;
	}
	while (power)
	{
		put_div(n, power, fd);
		power--;
	}
}
