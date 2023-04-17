/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:38:39 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/17 14:44:21 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str != '\0')
	{
		if (*str >= 65 && *str <= 90)
			str++;
		else
			return (0);
	}
	return (1);
}

/*
int main(void)
{
    printf("OK: %d\n" , ft_str_is_uppercase("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
    printf("NG: %d\n" , ft_str_is_uppercase("az"));
    printf("OK: %d\n" , ft_str_is_uppercase("AZ"));
    printf("OK: %d\n" , ft_str_is_uppercase(""));
    return (0);
}
*/
