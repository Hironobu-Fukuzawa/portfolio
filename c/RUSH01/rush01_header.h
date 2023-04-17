/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 02:35:35 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/12 04:18:29 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

# ifndef LENGTH
#  define LENGTH 4
# endif

/*void	ft_putchar(char c);*/
void	ft_putnbr(int nb);
void	ft_print_puzzle(int **puzzle);
int		is_available(int **puzzle, int row, int col, int num);
int		build_board(int **puzzle, int row, int col);
int		build_board2(int **puzzle, int row, int col, int i);
int		check_if_legal(char **puzzle, int row, int column, char number);
int		check_empty_spaces(char **puzzle, int *row, int *column);

