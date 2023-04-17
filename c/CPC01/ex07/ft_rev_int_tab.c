/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:18:15 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/21 17:21:24 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	*array;
	int	i;

	i = 0;
	array = malloc(sizeof(int *) * size);
	while (i <= size - 1)
	{
		if (i <= (size - 1) / 2)
		{
			array[i] = tab[i];
			array[size - 1 - i] = tab[size - 1 - i];
		}
		tab[size - 1 - i] = array[i];
		i++;
	}
}

/*
int main(void)
{
    int array[11];
	
	array[0] = 0;
    array[1] = 3;
    array[2] = 5;
    array[3] = 7;
    array[4] = 9;
    array[5] = 11;
    array[6] = 13;
    array[7] = 15;
    array[8] = 17;
    array[9] = 19;
    array[10] = 222;
    ft_rev_int_tab(&array[0], 11);
    printf("array[0]: %d\n", array[0]);
    printf("array[1]: %d\n", array[1]);
    printf("array[2]: %d\n", array[2]);
    printf("array[3]: %d\n", array[3]);
    printf("array[4]: %d\n", array[4]);
    printf("array[5]: %d\n", array[5]);
    printf("array[6]: %d\n", array[6]);
    printf("array[7]: %d\n", array[7]);
    printf("array[8]: %d\n", array[8]);
    printf("array[9]: %d\n", array[9]);
    printf("array[10]: %d\n", array[10]);
}
*/
