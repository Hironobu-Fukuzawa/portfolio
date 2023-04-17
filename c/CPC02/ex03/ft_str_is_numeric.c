/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:21:16 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/17 14:05:07 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str != '\0')
	{
		if (*str >= 48 && *str <= 57)
			str++;
		else
			return (0);
	}
	return (1);
}

/*
int	main(void)
{
	printf("OK: %d\n" , ft_str_is_numeric("0123456789"));
	printf("NG: %d\n" , ft_str_is_numeric("012345678z"));
	printf("OK: %d\n" , ft_str_is_numeric(""));
	return (0);
}
*/
