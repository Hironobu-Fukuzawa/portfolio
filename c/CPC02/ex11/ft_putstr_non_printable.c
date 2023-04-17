/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 15:49:46 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/21 15:36:29 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char	c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	int		div;
	int		mod;
	char	*hex;

	hex = "0123456789abcdef";
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
		{
			ft_putchar(str[i]);
		}
		else
		{
			div = str[i] / 16;
			mod = str[i] % 16;
			ft_putchar('\\');
			ft_putchar(hex[div]);
			ft_putchar(hex[mod]);
		}
		i++;
	}
}

/*
int	main(void)
{
	ft_putstr_non_printable("Co\ncou v\tas bi\ven ");
	return (0);
}
*/
