/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 22:02:31 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/20 15:40:09 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (*to_find == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (str[i + j] == to_find[j] && str[i + j] != '\0')
			{
				if (to_find[j + 1] == '\0')
					return (&str[i]);
				j++;
			}
		}
		i++;
	}
	return (0);
}

/*
int	main(void)
{
	char	*test = {"ABCDEFGH"};
	char	*test2 = {"CD"};
	char	*test3 = {""};

	printf("%p\n", &test[0]);
	printf("%p\n", &test[1]);
	printf("%p\n", &test[2]);
	printf("Point:%p\n", ft_strstr(test, test2));
	printf("String:%s\n", ft_strstr(test, test2));
	printf("Point:%p\n", ft_strstr(test, test3));
	printf("String:%s\n", ft_strstr(test, test3));
	printf("Str null:%s\n", ft_strstr(test3, test));	
	printf("--------------\n");
	printf("Point:%p\n", strstr(test, test2));
	printf("String:%s\n", strstr(test, test2));
	printf("POint:%p\n", strstr(test, test3));
	printf("String:%s\n", strstr(test, test3));
	printf("Str null:%s\n", strstr(test3, test));
	
	return (0);
}
*/
