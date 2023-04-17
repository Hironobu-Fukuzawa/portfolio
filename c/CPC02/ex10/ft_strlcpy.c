/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:26:06 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/19 12:33:06 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

unsigned	long	ft_strlcpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (src[count] != '\0')
		count++;
	while (i < n)
	{
		if (i == n - 1)
			*dest = '\0';
		else if (count <= n && i == count)
			*dest = '\0';
		else
			*dest = *src;
		src++;
		dest++;
		i++;
	}
	return (count);
}

/*
int	main(void)
{
	char	dest[] = "zzzzzzzzzzz";
	char	dest2[] = "zzzzzzzzzzz";
	printf("strlcpy1: %lu\n", strlcpy(dest, "Arigatou",10));
	printf("strlcpy dest: %s\n", dest);
	printf("ft_strlcpy1: %lu\n", ft_strlcpy(dest2, "Arigatou",10));
	printf("ft_strlcpy dest2: %s\n", dest2);
	return (0);
}
*/
