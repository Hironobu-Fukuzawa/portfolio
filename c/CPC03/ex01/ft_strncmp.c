/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:52:43 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/20 15:39:58 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				diff;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		diff = s1[i] - s2[i];
		if (diff > 0)
			return (1);
		else if (diff < 0)
			return (-1);
		i++;
	}
	return (0);
}

/*
int	main(void)
{
	printf("%d\n", strncmp("12311x" ,"12300" ,3));
	printf("%d\n", strncmp("12311x" ,"12300" ,4));
	printf("%d\n", strncmp("12300" ,"12311x" ,3));
	printf("%d\n", strncmp("12300x" ,"12300" ,10));
	printf("%d\n", strncmp("12300" ,"12300x" ,10));
	printf("%d\n", strncmp("12300" ,"12300x" ,0));
	printf("------------\n");
	printf("%d\n", ft_strncmp("12311x" ,"12300" ,3));
	printf("%d\n", ft_strncmp("12311x" ,"12300" ,4));
	printf("%d\n", ft_strncmp("12300" ,"12311x" ,3));
	printf("%d\n", ft_strncmp("12300x" ,"12300" ,10));
	printf("%d\n", ft_strncmp("12300" ,"12300x" ,10));
	printf("%d\n", ft_strncmp("12300" ,"12300x" ,0));
	return (0);
}
*/
