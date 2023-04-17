/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 19:18:09 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/21 18:00:37 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	swap;

	i = 0;
	while (i < size - 1)
	{
		j = size - 1;
		while (j > 0)
		{
			if (*(tab + j - 1) > *(tab + j))
			{
				swap = *(tab + j - 1);
				*(tab + j - 1) = *(tab + j);
				*(tab + j) = swap;
			}
			j--;
		}
		i++;
	}
}

/*
int main(void)
{
    int array[11];
	
	array[0] = 18;
    array[1] = 8;
    array[2] = 5;
    array[3] = 222;
    array[4] = 9;
    array[5] = 1;
    array[6] = 130;
    array[7] = 0;
    array[8] = 17;
    array[9] = 9;
    array[10] = 22;
    ft_sort_int_tab(&array[0], 11);
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
