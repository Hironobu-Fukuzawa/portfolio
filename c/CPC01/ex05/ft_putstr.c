/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:19:11 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/17 21:51:15 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

/*
int main(void)
{
	char	*str = "AbCde918lzz;;";
	char	*str_2 = "42 is \\0 Maybe it does not work as expected ?!";

    ft_putstr(str);
    ft_putstr(str_2);
}
*/
