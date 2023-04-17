/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:11:33 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/09 16:01:52 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}

void	ft_print_line(int x, int y, int b, int c)
{
	char	d[2];
	char	e[2];

	d[0] = '0';
	d[1] = '0';
	e[0] = '0';
	e[1] = '0';
	d[0] += x;
	d[1] += y;
	e[0] += b;
	e[1] += c;
	ft_putchar(d[0]);
	ft_putchar(d[1]);
	ft_putchar(' ');
	ft_putchar(e[0]);
	ft_putchar(e[1]);
	if (x == 9 && y == 8)
		return ;
	else
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb_helper(int a, int b)
{	
	int		x;
	int		y;
	int		i;

	i = 0;
	while (i < 99)
	{
		x = i / 10;
		y = i % 10;
		while (a <= 9)
		{	
			while (b <= 9)
			{
				if ((a == x && b > y) || a > x)
					ft_print_line(x, y, a, b);
				b++;
			}
			b = 0;
			a++;
		}
		a = 0;
		i++;
	}
	return ;
}

void	ft_print_comb2(void)
{	
	ft_print_comb_helper(0, 0);
	return ;
}
