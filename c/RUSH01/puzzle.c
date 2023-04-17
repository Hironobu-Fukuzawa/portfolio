/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puzzle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 02:01:06 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/12 21:37:39 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rush01_header.h"
#include <stdlib.h>

int		**ft_error(void)
{
	write(1, "Error!\n", 7);
	return (0);
}

int		**ft_create_puzzle(char **argv)
{
	int **puzzle;
	int i;
	int j;

	i = 1;
	j = 0;
	puzzle = (int**)malloc(sizeof(int*) * 4);
	while (i < 10)
	{
		puzzle[i - 1] = (int*)malloc(sizeof(int) * 4);
			while (j < 9)
			{
				if (argv[i][j] == 0)
					return (ft_error());
				if ((argv[i][j] - '0') < 0)
					puzzle[i - 1][j] = 0;
				else
					puzzle[i - 1][j] = (argv[i][j] - '0');
				j++;
			}
		j = 0;
		i++;
	}
	return (puzzle);
}

int		build_board(int **puzzle, int row, int col)
{
	int i;
	
	if (row < 4 && col < 4)
	{
		if (puzzle[row][col] != 0)
		{
			if ((col + 1) < 4)
				return (build_board(puzzle, row, col + 1));
			else if ((row + 1) < 4)
				return (build_board(puzzle, row + 1, 0));
			else
				return (1);
		}
		else
		{
			i = 0;
			return (build_board2(puzzle, row, col, i));
		}
		return (0);
	}
	else
		return (1);
}

int     build_board2(int **puzzle, int row, int col, int i)
{
	    while (i < 4)
			    {
					if (is_available(puzzle, row, col, i + 1))
					{
						puzzle[row][col] = i + 1;
						if ((col + 1) < 4)
						{
							if (build_board(puzzle, row, col + 1))
								return (1);
							else
								puzzle[row][col] = 0;
						}
						else if ((row + 1) < 4)
						{
							if (build_board(puzzle, row + 1, 0))
								return (1);
							else
								puzzle[row][col] = 0;
						}
						else
							return (1);
					}
					i++;
					    }
		    return (0);
}
