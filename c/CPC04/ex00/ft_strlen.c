/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 13:52:53 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/19 22:28:57 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

/*
int main(void)
{
    printf("Return Value: %lu\n", strlen(""));
    printf("Return Value: %lu\n", strlen("ABCD"));
    printf("Return Value: %d\n", ft_strlen(""));
    printf("Return Value: %d\n", ft_strlen("ABCD"));
    return (0);
}
*/
