/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:50:55 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/13 11:53:11 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_strlen(char *str)
{
	unsigned int	length;

	length = 0;
	while (*str != '\0')
	{
		str++;
		length++;
	}
	return (length);
}

/*
int main(int argc, char *argv[])
{
    if (argc != 2)
		return (1);
    printf("Pointer of argv[1]: %p\n", argv[1]);
	printf("Value of *argv[1]: %d\n", *argv[1]);
    printf("Length of string: %d\n", ft_strlen(argv[1]));
}
*/
