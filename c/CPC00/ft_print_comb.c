/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:11:33 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/12 20:09:50 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}

void	ft_check_and_print(int a, int b, int c)
{
	char	d[3];

	d[0] = '0';
	d[1] = '0';
	d[2] = '0';
	if (a != b && b != c && c != a)
	{	
		d[0] += a;
		d[1] += b;
		d[2] += c;
		ft_putchar(d[0]);
		ft_putchar(d[1]);
		ft_putchar(d[2]);
		if (a != 7 || b != 8 || c != 9)
			write(1, ", ", 2);
		return ;
	}
}

void	ft_print_comb_helper(int a, int b, int c)
{	
	while (a <= 9)
	{
		b = a + 1;
		while (b <= 9)
		{
			c = b + 1;
			while (c <= 9)
			{
				ft_check_and_print(a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}


void	ft_print_comb(void)
{	
	ft_print_comb_helper(0, 0, 0);
	return ;
}
