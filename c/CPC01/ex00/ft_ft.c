/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 21:43:15 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/17 21:49:56 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_ft(int *nbr)
{
	int	p;

	p = 42;
	*nbr = p;
}

/*
int main(int argc, char *argv[])
{
    int a;
	
	if (argc != 2)
		return (1);
    a = *argv[1];
    printf("Address of a: %p\n", &a);
    printf("Value of a: %d\n", *(&a));
    ft_ft(&a);
    printf("Address of a: %p\n", &a);
    printf("Value of a: %d\n", *(&a));
}
*/
