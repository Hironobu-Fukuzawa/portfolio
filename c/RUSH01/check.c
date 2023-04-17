/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 02:57:40 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/12 04:20:33 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01_header.h"

int		used_in_row(char **puzzle, int row, char number)
{
		int column;

			column = 0;
				while (column < LENGTH)
						{
									if (puzzle[row][column] == number)
													return (1);
											column++;
												}
					return (0);
}

int		used_in_column(char **puzzle, int column, char number)
{
		int row;

			row = 0;
				while (row < LENGTH)
						{
									if (puzzle[row][column] == number)
													return (1);
											row++;
												}
					return (0);
}

int		used_in_box(char **puzzle, int row, int column, char number)
{
		int x;
			int y;

				x = 0;
					while (x < 3)
							{
										y = 0;
												while (y < 3)
															{
																			if (puzzle[x + row][y + column] == number)
																								return (1);
																						y++;
																								}
														x++;
															}
						return (0);
}

int		check_if_legal(char **puzzle, int row, int column, char number)
{
		if (!used_in_row(puzzle, row, number) &&
						!used_in_column(puzzle, column, number) &&
								!used_in_box(puzzle, row - (row % 3), column - (column % 3), number))
					return (1);
			return (0);
}


int		check_empty_spaces(char **puzzle, int *row, int *column)
{
		*row = 0;
			while (*row < LENGTH)
					{
								*column = 0;
										while (*column < LENGTH)
													{
																	if (puzzle[*row][*column] == '0')
																						return (1);
																				*column += 1;
																						}
												*row += 1;
													}
				return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
		int		count;
			int		b[10];

				count = 0;
					if (nb < 0)
							{
										ft_putchar('-');
												nb = -nb;
													}
						if (nb == 0)
								{
											ft_putchar(nb + 48);
												}
							while (nb > 0)
									{
												b[count] = nb % 10;
														count++;
																nb /= 10;
																	}
								while (count > 0)
										{
													count--;
															ft_putchar(b[count] + 48);
																}
}

void	ft_print_puzzle(int **puzzle)
{
		int i;
			int j;

				i = 0;
					j = 0;
						while (i < 9)
								{
											while (j < 8)
														{
																		ft_putnbr((puzzle[i][j]));
																					ft_putchar(' ');
																								j++;
																										}
													ft_putnbr(puzzle[i][j]);
															ft_putchar('\n');
																	j = 0;
																			i++;
																				}
}

int		is_available(int **puzzle, int row, int col, int num)
{
		int row_start;
			int col_start;
				int i;

					row_start = (row / 3) * 3;
						col_start = (col / 3) * 3;
							i = 0;
								while (i < 9)
										{
													if (puzzle[row][i] == num)
																	return (0);
															if (puzzle[i][col] == num)
																			return (0);
																	if (puzzle[row_start + (i % 3)][col_start + (i / 3)] == num)
																					return (0);
																			i++;
																				}
									return (1);
}










