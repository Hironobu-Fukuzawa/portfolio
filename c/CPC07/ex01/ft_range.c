/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 10:53:16 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/10/02 11:20:30 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *ft_range(int min, int max)
{
	int	*numbers;
	int	i;
	int	total_count;

	i = 0;
	total_count = max - min;

	if (min >= max)
		return (NULL);
	numbers = (int *) malloc (sizeof(int) * (total_count));
	if (!numbers)
		return (NULL);
	while (i <  total_count)
	{
		numbers[i] = min;
		i++;
		min++;
	}
	return numbers;
}

/*
int	main(void)
{
	int *result;
	int	i;

	i = 0;
	result = ft_range(-10, 15);

	while (i < 25)
	{
		printf("%d\n", result[i]);
		i++;
	}
	return (0);
}
*/
