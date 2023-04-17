/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:45:06 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/20 00:48:48 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char	c)
{
	write(1, &c, 1);
}

int	ft_return_sign(char	*str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			count++;
		i++;
	}
	if (count % 2 == 1)
		return (-1);
	return (1);
}

char	*ft_skip_sign(char	*str)
{
	while (*str == 43 || *str == 45)
		str++;
	return (str);
}

int	ft_return_num(char	*str)
{
	int		num;

	num = 0;
	while (*str >= 48 && *str <= 57)
	{
		num = num * 10 + (*str - 48);
		str++;
	}	
	return (num);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	num;

	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	sign = ft_return_sign(str);
	str = ft_skip_sign(str);
	num = ft_return_num(str);
	return (sign * num);
}

/*
int	main(void)
{
	char	str[] = "      \t\r\v\f\r+--+-----+23566+44";
	printf("%d\n", ft_atoi(str));
	return (0);
}
*/
