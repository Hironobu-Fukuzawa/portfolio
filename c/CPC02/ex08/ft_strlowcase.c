/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 12:52:32 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/17 21:02:15 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	char	*origin;

	origin = str;
	while (*str != '\0')
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		str++;
	}
	return (origin);
}

/*
int main(void)
{
	char	test[] = "abcdefgstuwxyz0123456789ABCDEFTEAEFAEFJLNAEFXSAZZAWKMDK";

	ft_strlowcase(test);
	printf("%s\n", test);
	return (0);
}
*/
