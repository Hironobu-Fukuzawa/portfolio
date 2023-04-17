/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:33:46 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/19 12:19:43 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str != '\0')
	{
		if ((*str >= 65 && *str <= 90) || \
				(*str >= 97 && *str <= 122))
			str++;
		else
			return (0);
	}
	return (1);
}

/*
int	main(void)
{
	printf("OK: %d\n" , ft_str_is_alpha("abcdewxyzABCDUVWXYZ"));
	printf("NG: %d\n" , ft_str_is_alpha("abcdefghiyzABCDEUVWXY@"));
	printf("OK: %d\n" , ft_str_is_alpha(""));
	printf("NG: %d" , ft_str_is_alpha("abZdAer9"));
	return (0);
}
*/
