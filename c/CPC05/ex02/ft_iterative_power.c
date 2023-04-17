/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:15:46 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/23 19:54:05 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	base;

	base = 1;
	if (nb == 0 && power == 0)
		return (1);
	else if ((nb == 0 && power != 0) || power < 0)
		return (0);
	else
	{
		while (power > 0)
		{
			base = base * nb;
			power--;
		}
	}
	return (base);
}

/*
int	main(void)
{
	printf("%d\n", ft_iterative_power(4, 3));
	printf("%d\n", ft_iterative_power(0, 0));
	printf("%d\n", ft_iterative_power(0, -1));
	printf("%d\n", ft_iterative_power(-1, 5));
	printf("%d\n", ft_iterative_power(20, -1));
}
*/
