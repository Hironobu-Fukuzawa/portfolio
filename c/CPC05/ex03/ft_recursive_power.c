/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:32:42 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/24 13:34:01 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	else if ((nb == 0 && power != 0) || power < 0)
		return (0);
	else if (power == 1)
		return (nb);
	return (nb * ft_recursive_power(nb, power - 1));
}

/*
int	main(void)
{
	printf("0:%d\n", ft_recursive_power(-3124,-855));
	printf("1:%d\n", ft_recursive_power(0,0));
	printf("1:%d\n", ft_recursive_power(3802,0));
	printf("3591:%d\n", ft_recursive_power(3591,1));
	printf("9:%d\n", ft_recursive_power(3, 2));
	printf("64:%d\n", ft_recursive_power(4, 3));
	printf("625:%d\n", ft_recursive_power(5, 4));
	printf("-7776:%d\n", ft_recursive_power(-6,5));
	printf("1:%d\n", ft_recursive_power(-1,10));
}
*/
