/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 05:05:56 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/19 21:44:16 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <stdlib.h>
*/

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	a_val;
	int	b_val;

	a_val = *a;
	b_val = *b;
	*a = a_val / b_val;
	*b = a_val % b_val;
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
    printf("Value of div: %d\n", a);
    printf("Value of mod: %d\n", b);
    ft_ultimate_div_mod(&a, &b);
    printf("Result of div: %d\n", a);
    printf("Result of mod: %d\n", b);
}
*/
