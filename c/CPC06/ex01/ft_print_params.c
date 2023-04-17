/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:50:27 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/22 19:03:33 by hfukuzaw         ###   ########.fr       */
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
	(void)argc;
	argv++;
	while (*argv != NULL)
	{
		while (**argv != '\0')
		{
			ft_putchar(**argv);
			(*argv)++;
		}
		ft_putchar('\n');
		argv++;
	}
	return (0);
}
