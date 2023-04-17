/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:34:10 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/18 15:59:09 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str != '\0')
	{
		if (*str >= 32 && *str <= 126)
			str++;
		else
			return (0);
	}
	return (1);
}

/*
int main(void)
{
    printf("OK: %d\n" , ft_str_is_printable("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
    printf("OK: %d\n" , ft_str_is_printable("[\\]^_`"));
    printf("OK: %d\n" , ft_str_is_printable("abcdefghijklmnopqrstuvwxyz"));
    printf("OK: %d\n" , ft_str_is_printable("{|}~"));
    printf("NG: %d\n" , ft_str_is_printable("\n"));
    printf("NG: %d\n" , ft_str_is_printable("¥"));
	return (0);
}
*/
