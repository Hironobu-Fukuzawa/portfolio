/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:05:05 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/24 14:11:11 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	is_prime(int nb)
{
	long	i;

	i = 2;
	while (nb >= i * i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (nb > 1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	i = 2;
	if (is_prime(nb))
		return (nb);
	else
	{
		nb++;
		while (!is_prime(nb))
			nb++;
		return (nb);
	}
}

/*
int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	printf("%d\n", ft_find_next_prime(atoi(argv[1])));
}
*/
