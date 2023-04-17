/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:58:14 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/12 19:32:18 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "rush01_header.h"

/*
char	**create_array(char **argv);
void	print_array(char** puzzle);
*/

int		build_board2(int **puzzle, int row, int col, int i);
int		**ft_error(void);
int		build_board(int **puzzle, int row, int col);
int		**ft_create_puzzle(char **argv);
void	ft_print_puzzle(int **puzzle);

int	main(int argc, char **argv)
{
	int **puzzle;

	if (argc != 10)
	{
		write(1, "Error!\n", 7);
		return (0);
	}

	puzzle = ft_create_puzzle(argv);
	printf("%d\n:", puzzle[0][0]);
	if (puzzle == 0)
	{
		return (0);
	}
	if (build_board(puzzle, 0, 0))
		ft_print_puzzle(puzzle);
	else
		write(1, "Error!\n", 7);
	return (0);
}
