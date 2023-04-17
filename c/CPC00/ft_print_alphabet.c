/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:58:32 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/08 16:39:28 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	c;
	int		i;

	c = 'a';
	i = 0;
	while (i < 26)
	{	
		write(1, &c, 1);
		c += 1;
		i ++;
	}
	return ;
}