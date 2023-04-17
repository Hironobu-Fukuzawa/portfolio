/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 04:42:01 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/13 11:40:05 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <stdlib.h>
*/

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	int	div_val;
	int	mod_val;

	div_val = a / b;
	mod_val = a % b;
	*div = div_val;
	*mod = mod_val;
}

/*
int main(int argc, char *argv[])
{
    int a;
    int b;
    int div;
    int mod;
	
	div = 0;
    mod = 0;
    if (argc != 3)
		return (1);
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    printf("Value of div: %d\n", div);
    printf("Value of mod: %d\n", mod);
    ft_div_mod(a, b, &div, &mod);
    printf("Result of div: %d\n", div);
    printf("Result of mod: %d\n", mod);
}
*/
