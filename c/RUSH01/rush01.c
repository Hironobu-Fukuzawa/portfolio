/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:58:14 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/14 16:50:07 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

# ifndef N
#  define N 4
# endif

int **initial_grid;
int **board;
int **condition;

initial_grid =
{
	{0, 0, 0, 0}
	{0, 0, 0, 0}
	{0, 0, 0, 0}
	{0, 0, 0, 0}
};

ft_putchar(char c)
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


void print_grid(int **puzzle)
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


int check_param(int **param[][])
{
	int	i;
	int	j;
	i = 0;
	j = 0;
	/* all each value is 1 <= x <= 4, if not  return(1) */
	while (i <= 3)
	{
		while (j <= 3)
		{
			if (param[i][j] < 1 || param[i][j] > 4)
			{
				return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void    print_error()
{
	ft_putchar('E');
	ft_putchar('r');
	ft_putchar('r');
	ft_putchar('o');
	ft_putchar('r');
	ft_putchar('\n');
}

int **set_grid(void)
{
	int **grid;
	int	i;
	int	j;

	i = 0;
	grid = malloc(sizeof(int) * N);
	while (i < N)
	{
		j = 0;
		grid[i] = malloc(sizeof(int) * N);
		if (grid == NULL)
			return NULL;
		while (j < N)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	return (grid);
}


int	ft_check_row_col(int x, int y, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < N)
	{
		if(board[y][i] == n && i != x)
			return (0);
		++i;
	}
	while (j < N)
	{
		if (board[j][x] == n && j != y)
			return (0);
		++j;
	}
	printf("OK col and row\n");
	return (1);
}

int	ft_count_coltop(int index)
{
	int	i;
	int	count;
	int	max_h;

	i = 0;
	count = 1;
	max_h = board[0][index];
	while (i < N)
	{
		if (board[i][index] > max_h)
		{
			++count;
			max_h = board[i][index];
		}
		++i;
	}
	return count;
}

int	ft_count_coldown(int index)
{
	int	i;
	int	count;
	int	max_h;

	i = N;
	count = 1;
	max_h = board[N - 1][index];
	while (i > 0)
	{
		--i;
		if (board[i][index] > max_h)
		{
			++count;
			max_h = board[i][index];
		}
	}
	return count;
}

int	ft_count_rowleft(int index)
{
	int	i;
	int	count;
	int	max_h;

	i = 0;
	count = 0;
	max_h = board[index][0];
	while (i < N)
	{
		if (board[index][i] > max_h)
		{
			++count;
			max_h = board[index][i];
		}
		++i;
	}
	return count;
}

int	ft_count_rowright(int index)
{
	int	i;
	int	count;
	int	max_h;

	i = N;
	count = 1;
	max_h = board[index][N - 1];
	while (i > 0)
	{
		--i;
		if (board[index][i] > max_h)
		{
			++count;
			max_h = board[index][i];
		}
	}
	return count;
}

int	ft_count(int type, int index)
{
	if (type == 0)
		return (ft_count_coltop(index));
	else if (type == 1)
		return (ft_count_coldown(index));
	else if (type == 2)
		return (ft_count_rowleft(index));
	else
		return (ft_count_rowright(index));
}


int	ft_check_fulfill_condition(void)
{
	int	type;
	int index;

	type = 0;
	index = 0;
	while (type < N)
	{
		while (index < N)
		{
			if (condition[type][index] != ft_count(type, index))
				return 0;
			++index;
		}
		++type;
	}
	return 1;
}


int	ft_solver(int point)
{
	printf("Point: %d = (%d, %d)\n", point, point % N, point / N);
	printf("Board\n");
	ft_print_board();
	if (point == N * N)
		return (ft_check_fulfill_condition());
	int	x;
	int	y;

	x = point % N;
	y = point / N;
	if (board[y][x])
		return ft_solver(point + 1);
	else
	{
		int	n;

		n = 1;
		printf("Start while in point %d\n", point);
		while (n <= N)
		{
			printf("assign %d to point %d\n", n, point);
			board[y][x] = n;
			if (ft_check_row_col(x, y, n)){
				if (ft_solver(point + 1))
					return 1;
			}
			++n;
		}
		board[y][x] = 0;
		return 0;
	}
}


int	main(int argc, char **argv)
{
	int** grid;
	int	result;

	if(argc != 2){
		print_error();
	}
	/*
	while(i <= argc - 1)
	{
		printf("%s\n", argv[i]);
		i++;
	}
	*/
	/*
	if(check_param(int **visible_array[][]) == 1)
	{
		print_error();
	}
	*/	
	grid = set_grid();
	if (grid == NULL)
		return (1);
	result = ft_solver(0);
	if (result == NULL)
		return (1);
	else if (result == 0)
	{
		print_error();
	}
	else
	{
		print_array();
	}
	free(grid);
	free(initial_grid);
}

