/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:55:04 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/17 20:59:55 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

char	*ft_strupcase(char *str)
{
	char	*origin;

	origin = str;
	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
			*str = *str - 32;
		str++;
	}
	return (origin);
}

/*
int main(void)
{
	char	test[] = "abcdefgstuwxyz0123456789ABCDEFTEAEFAEFJLNAEFXSAZZAWKMDK";

	printf("%s\n", ft_strupcase(test));
	return (0);
}
*/
