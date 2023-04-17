/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:15:35 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/22 19:03:20 by hfukuzaw         ###   ########.fr       */
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
	while (**argv != '\0')
	{
		ft_putchar(**argv);
		(*argv)++;
	}
	ft_putchar('\n');
	return (0);
}
