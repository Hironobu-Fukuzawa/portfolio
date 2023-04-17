/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 11:15:48 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/10/02 11:41:14 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int sum;

	i = 0;
	sum = max - min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *)malloc(sizeof(int) * (max - min));
	if (!*range)
		return (-1);
	while (i < sum)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (i);
}

/*
int	main(void)
{
	int	**test;
	int	size;
	int	i;

	i = 0;
	size = ft_ultimate_range(test, -8, 39);
	printf("size:%d\n", size);
	while (i < 25)
	{
		printf("%d\n", test[0][i]);
		i++;
	}
	return (0);
}
*/
