/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:06:42 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/22 21:49:09 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int	argc, char	**argv)
{
	int		size;
	int		i;

	size = argc - 1;
	if (argc == 1)
		return (1);
	while (size > 0)
	{
		i = 0;
		while (argv[size][i] != '\0')
		{
			ft_putchar(argv[size][i]);
			i++;
		}
		ft_putchar('\n');
		size--;
	}
	return (0);
}
