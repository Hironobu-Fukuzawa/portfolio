/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:49:23 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/21 17:38:40 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

/*
int	main(void)
{
	char	*test1, *test2, *test3;
	char str[] = "ABC";
    char str1[] = "ABC";
	char str2[] = "ABD";
	char str3[] = "B";
	char str4[] = "AAAA";

	test1 = "abcde";
	test2 = "abcdef";
	test3 = "abc";
	printf("%d\n", strcmp(str,str1));
	printf("%d\n", strcmp(str,str2));
	printf("%d\n", strcmp(str,str3));
	printf("%d\n", strcmp(str,str4));
	printf("%d\n", strcmp(test1,test2));
	printf("%d\n", strcmp(test1,test3));
	printf("%d\n", ft_strcmp(str,str1));
	printf("%d\n", ft_strcmp(str,str2));
	printf("%d\n", ft_strcmp(str,str3));
	printf("%d\n", ft_strcmp(str,str4));
	printf("%d\n", ft_strcmp(test1,test2));
	printf("%d\n", ft_strcmp(test1,test3));
	return (0);
}
*/
