/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:07:46 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/19 12:35:55 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*
int	main(void)
{
	char	test[] = "0000000000";
	char	test2[] = "0000000000";
	char	test3[10];
	printf("Res1: %s\n", ft_strncpy(test, "Arigatou", 8));
	printf("Res2: %s\n", ft_strncpy(test2, "Arigatou", 5));
	printf("Res3: %s\n", ft_strncpy(test3, "Arigatou", 5));	
	printf("Strncpy1: %s\n", strncpy(test, "Arigatou", 8));
	printf("Strncpy2: %s\n", strncpy(test2, "Arigatou", 5));
	printf("Strncpy3: %s\n", strncpy(test3, "Arigatou", 5));
	return (0);
}
*/
