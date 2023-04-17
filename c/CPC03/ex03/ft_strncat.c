/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:15:18 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/20 15:14:31 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	size;

	i = 0;
	j = 0;
	size = 0;
	while (src[size] != '\0')
		size++;
	while (dest[i] != '\0')
		i++;
	if (size >= nb)
		size = nb;
	while (j < size)
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
	unsigned	int	nb;

	nb = 3;
	test2 = "EFGHIABCDEF";
	printf("%s", ft_strncat(test1, test2, 10));
	printf("%s", strncat(test1, test2, 10));
}
*/
