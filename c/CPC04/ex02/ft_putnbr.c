/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:30:10 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/19 15:43:05 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}

void	ft_putnbr(int n)
{
	int	m_max;

	m_max = -2147483648;
	if (n == m_max)
	{
		ft_putnbr((n / 10));
		ft_putchar((char)(((m_max % 10) * -1) + '0'));
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(n * -1);
	}
	else if (n < 10)
	{
		ft_putchar((char)(n + '0'));
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putchar((char)((n % 10) + '0'));
	}
	return ;
}

/*
int	main(void)
{
	ft_putnbr(-2147483648);
	return (0);
}
*/
