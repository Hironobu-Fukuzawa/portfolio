/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 04:16:09 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/13 11:32:24 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <stdlib.h>
*/

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

/*
int	main(int argc, char *argv[])
{
    int a;
    int b;

	if (argc != 3)
		return (1);
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    printf("Address of a: %p\n", &a);
    printf("Value of a: %d\n", *(&a));
    printf("Address of b: %p\n", &b);
    printf("Value of b: %d\n", *(&b));
    ft_swap(&a, &b);
    printf("Address of a: %p\n", &a);
    printf("Modified Value of a: %d\n", *(&a));
    printf("Address of b: %p\n", &b);
    printf("Modified Value of b: %d\n", *(&b));
}
*/
