/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 03:46:49 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/19 21:38:14 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* #include <stdio.h> */

void	ft_ultimate_ft(int *********nbr)
{
	int	p;

	p = 42;
	*********nbr = p;
}

/*
int main(int argc, char *argv[])
{
    int a;
    int *p;
    int **pp;
    int ***ppp;
    int ****pppp;
    int *****ppppp;
    int ******pppppp;
    int *******ppppppp;
    int ********pppppppp;
	
	if (argc != 2)
		return (1);
    a = *argv[1];
    p = &a;
    pp = &p;
    ppp = &pp;
    pppp = &ppp;
    ppppp = &pppp;
    pppppp = &ppppp;
    ppppppp = &pppppp;
    pppppppp = &ppppppp;
    printf("Address of a: %p\n", &a);
    printf("Value of a: %d\n", *(&a));
    ft_ultimate_ft(&pppppppp);
    printf("Address of a: %p\n", &a);
    printf("Value of a: %d\n", *(&a));
}
*/
