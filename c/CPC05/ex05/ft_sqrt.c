/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:27:05 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/23 19:53:13 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	ft_sqrt(int nb)
{
	int	sqrt;
	int	sq;

	sqrt = 0;
	sq = 0;
	while (sqrt < nb)
	{
		sqrt++;
		sq = sqrt * sqrt;
		if (sq == nb)
			return (sqrt);
		else if (sq > nb)
			return (0);
	}
	return (0);
}

/*
int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	printf("%d\n", ft_sqrt(atoi(argv[1])));
}
*/
