/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:15:18 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/19 13:06:21 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = 0;
	while (src[size] != '\0')
		size++;
	while (dest[i] != '\0')
		i++;
	while (j <= size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
int	main(void)
{
	char	test1[30] = "abcde";
	char	*test2;

	test2 = "EFGHI";
	printf("%s", ft_strcat(test1, test2));
	printf("%s", strcat(test1, test2));
}
*/
