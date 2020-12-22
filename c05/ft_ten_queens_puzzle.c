

#include <unistd.h>
#include <stdio.h>

void	print_chessboard(int chessboard[10][10])
{
	int		x;
	int		y;
	char	c;

	x = 0;
	while (x < 10)
	{
		y = 0;
		while (y < 10)
		{
			if (chessboard[x][y] == 1)
			{
				c = y + '0';
				write(1, &c, 1);
			}
			y++;
		}
		x++;
	}
	write(1, "\n", 1);
}

int		check_position(int chessboard[10][10], int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i <= x)
	{
		if (chessboard[i][y] == 1)
			return (0);
		i++;
	}
	i = x;
	j = y;
	while (--i >= 0 && --j >= 0)
	{
		if (chessboard[i][j] == 1)
			return (0);
	}
	i = x;
	j = y;
	while (--i >= 0 && ++j <= 9)
	{
		if (chessboard[i][j] == 1)
			return (0);
	}
	return (1);
}

void	fill_chessboard(int chessboard[10][10], int x, int y, int *counter)
{
	if (x == 10)
	{
		(*counter)++;
		print_chessboard(chessboard);
		return ;
	}
	while (y < 10)
	{
		if (check_position(chessboard, x, y))
		{
			chessboard[x][y] = 1;
			fill_chessboard(chessboard, x + 1, 0, counter);
			chessboard[x][y] = 0;
		}
		y++;
	}
}

int		ft_ten_queens_puzzle(void)
{
	int		chessboard[10][10];
	int		x;
	int		y;
	int		counter;

	counter = 0;
	x = 0;
	while (x < 10)
	{
		y = 0;
		while (y < 10)
		{
			chessboard[x][y] = 0;
			y++;
		}
		x++;
	}
	fill_chessboard(chessboard, 0, 0, &counter);
	return (counter);
}

int		main(void)
{
	printf("il numero di combinazioni e' %d\n", ft_ten_queens_puzzle());
}
