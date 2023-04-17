/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 20:28:16 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/20 00:39:46 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}

void	ft_putnbr(int n, int basenum, char	*base)
{
	int	m_max;

	m_max = -2147483648;
	if (n == m_max)
	{
		ft_putnbr(n / basenum, basenum, base);
		ft_putchar(base[(m_max % basenum)*-1]);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(n * -1, basenum, base);
	}
	else if (n < basenum)
	{
		ft_putchar(base[n]);
	}
	else
	{
		ft_putnbr(n / basenum, basenum, base);
		ft_putchar(base[n % basenum]);
	}
	return ;
}

int	ft_check_base(char	*base)
{
	int	i;
	int	j;

	i = 0;
	if (base[i] == '\0')
		return (1);
	while (base[i] != '\0')
	{
		j = i + 1;
		if (base[i] == 43 || base[i] == 45)
			return (1);
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (1);
	return (0);
}	

void	ft_putnbr_base(int nbr, char *base)
{
	int	basenum;

	basenum = 0;
	if (ft_check_base(base))
	{
		return ;
	}
	while (base[basenum] != '\0')
		basenum++;
	ft_putnbr(nbr, basenum, base);
}

/*
int	main(void)
{
	ft_putnbr_base(-2147483648, "");
	ft_putnbr_base(-2147483648, "0123456789ABCD5F");
	ft_putnbr_base(-2147483648, "1");
	ft_putnbr_base(-214, "0123456789ABCDEF");
	ft_putnbr_base(-2147, "0123456789ABCDEF");
	ft_putnbr_base(-2147483648, "0123456789ABCDEF");
	ft_putnbr_base(-2147483648, "0123456789");
	ft_putnbr_base(-214, "01");
}
*/
