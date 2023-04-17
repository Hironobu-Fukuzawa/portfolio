/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 18:10:41 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/05 12:24:46 by ttaniguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putline(int r_max, int column, int c_max)
{
	int	row;

	row = 1;
	while (row <= r_max)
	{
		if ((column == 1 && row == r_max) || (column == c_max && row == r_max))
		{
			ft_putchar('C');
		}
		else if ((column == 1 && row == 1) || (column == c_max && row == 1))
		{
			ft_putchar('A');
		}
		else if ((column != 1 && column != c_max) && (row != 1 && row != r_max))
		{
			ft_putchar(' ');
		}
		else
		{
			ft_putchar('B');
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
