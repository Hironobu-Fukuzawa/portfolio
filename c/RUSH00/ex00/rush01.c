/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 18:10:41 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/05 23:22:22 by nseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putline(int r, int co, int c)
{
	int	row;

	row = 1;
	while (row <= r)
	{
		if ((co == 1 && row == 1) || (co == c && row == r && c != 1 && r != 1))
		{
			ft_putchar('/');
		}
		else if ((co == 1 && row == r) || (co == c && row == 1))
		{
			ft_putchar('\\');
		}
		else if ((co != 1 && co != c) && (row != 1 && row != r))
		{
			ft_putchar(' ');
		}
		else
		{
			ft_putchar('*');
		}
		row ++;
	}
}

void	rush(int x, int y)
{
	int	index;

	index = 1;
	while (index <= y)
	{
		ft_putline(x, index, y);
		ft_putchar('\n');
		index ++;
	}
}
