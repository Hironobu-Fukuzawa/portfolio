/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:30:19 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/17 14:50:42 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str != '\0')
	{
		if (*str >= 97 && *str <= 122)
			str++;
		else
			return (0);
	}
	return (1);
}

/*
int main(void)
{
    printf("OK: %d\n" , ft_str_is_lowercase("abcdefghijklmnopqrstuvwxyz"));
    printf("NG: %d\n" , ft_str_is_lowercase("abcdefghijklmnopqrstuvwxyA"));
    printf("NG: %d\n" , ft_str_is_lowercase("A"));
    printf("OK: %d\n" , ft_str_is_lowercase("z"));
    return (0);
}
*/
