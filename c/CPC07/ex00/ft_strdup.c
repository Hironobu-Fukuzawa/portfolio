/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 10:37:18 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/10/02 11:20:46 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ft_strdup(char *src)
{
	char *s1;
	int		i;

	i = 0;
	while(src[i] != '\n')
		i++;
	s1 = (char *) malloc (sizeof(char) * (i + 1));
	if(!s1)
		return (NULL);
	i = 0;
	while (src[i] != '\n')
	{
		s1[i] = src[i];
		i++;
	}
	s1[i] = '\n';
	return s1;
}

/*
int main(void)
{
	char *test = "abcde";
	char *copy;

	copy = ft_strdup(test);
	printf("pointer1:%p\n", test);
	printf("copy:%s\n", copy);
	printf("pointer2:%p\n", copy);
	return (0);
}
*/
