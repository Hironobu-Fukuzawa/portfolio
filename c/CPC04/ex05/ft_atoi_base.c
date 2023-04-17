/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 20:28:16 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/20 17:24:07 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	sig;
	int	i;

	sig = 1;
	i = 0;
	while (*str && ((*str >= 9 && *str <= 13) || *str == 32))
		str++;
	while (*str && (*str == 43 || *str == 45))
	{
		if (*str == 45)
			sig *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		i = i * 10 + (*str - 48);
		str++;
	}
	return (sig * i);
}

int	ft_check_base(char	*base)
{
	int	i;
	int	j;

	i = 0;
	if (base[i] == '\0')
		return (1);
	while (base[i] != '\0')
	{
		j = i + 1;
		if (base[i] == 43 || base[i] == 45)
			return (1);
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (1);
	return (0);
}	

int	ft_atoi_base(char	*str, char *base)
{
	int	basenum;
	int	nbr;

	basenum = 0;
	if (ft_check_base(base))
		return (0);
	while (base[basenum] != '\0')
		basenum++;
	nbr = ft_atoi(str);
	return (nbr);
}

/*
int	main(void)
{
	printf("%d\n", ft_atoi_base("---+--+128ab", "01234"));
	printf("%d\n", ft_atoi_base("6D", "0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("101010111", "01"));
}
*/
