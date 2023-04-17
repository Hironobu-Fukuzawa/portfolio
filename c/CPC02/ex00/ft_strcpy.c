/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:52:23 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/18 15:05:33 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

char	*ft_strcpy(char *dest, char *src)
{
	char	*origin;

	origin = dest;
	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	if (*src == '\0')
		*dest = '\0';
	return (origin);
}

/*
int	main(void)
{
	char	dest[] = "zzzzzzzzzzzz";

	printf("ft dest: %s\n", ft_strcpy(dest, "Arigatou"));
	printf("dest: %s\n", strcpy(dest, "Arigatou"));
	return (0);
}
*/
