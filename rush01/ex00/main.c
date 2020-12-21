
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		*r;
int		**m;
int		n;
int		flag;

void	print(void)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (y < n)
	{
		x = 0;
		while (x < n)
		{
			c = m[x][y] + '0';
			write(1, &c, 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

int		initialize_m(void)
{
	int		i;
	int		j;

	i = 0;
	while (i < n)
	{
		if ((m[i] = malloc(n * sizeof(int))) == 0)
		{
			printf("Error in the creation of m");
			return (0);
		}
		j = 0;
		while (j < n)
		{
			m[i][j] = 0;
			j++;
		}
		i++;
	}
	return (1);
}

void	free_m(void)
{
	int		i;

	i = 0;
	while (i < n)
	{
		free(m[i]);
		i++;
	}
	free(m);
}

/*int		check_input(int argc, char **argv)
{
	return (1);
}
*/
int		check_requests_row(int y)
{
	int		counter;
	int		i;
	int		max;

	counter = 0;
	max = 0;
	i = 0;
	while (i < n)
	{
		if (m[i][y] > max)
		{
			max = m[i][y];
			counter++;
		}
		i++;
	}
	if (counter != r[2 * n + y])
		return (0);
	counter = 0;
	max = 0;
	i = n - 1;
	while (i >= 0)
	{
		if (m[i][y] > max)
		{
			max = m[i][y];
			counter++;
		}
		i--;
	}
	if (counter != r[3 * n + y])
		return (0);
	return (1);
}

int		check_requests_column(int x)
{
	int		counter;
	int		i;
	int		max;

	counter = 0;
	max = 0;
	i = 0;
	while (i < n)
	{
		if (m[x][i] > max)
		{
			max = m[x][i];
			counter++;
		}
		i++;
	}
	if (counter != r[x])
		return (0);
	counter = 0;
	max = 0;
	i = n - 1;
	while (i >= 0)
	{
		if (m[x][i] > max)
		{
			max = m[x][i];
			counter++;
		}
		i--;
	}
	if (counter != r[n + x])
		return (0);
	return (1);
}

int		check_char_row(int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (m[i][y] == m[j][y])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		check_char_column(int x)
{
	int		i;
	int		j;

	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (m[x][i] == m[x][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	fill_r(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (i % 2 == 0)
			r[i / 2] = str[i] - '0';
		i++;
	}
}

/*void	fill_m(int x, int y)
{
	if (y < 0)
	{
		flag = 0;
		return ;
	}
	else if (x < 0)
	{
		fill_m(n - 1, y - 1);
		return ;
	}
	m[x][y]++;
	if (m[x][y] > n)
	{
		m[x][y] = 0;
		fill_m(x - 1, y);
		return ;
	}
	else if ((x == n - 1) && (y < n - 1))
	{
		if (check_char_row(y) && check_requests_row(y))
		{
			m[0][y + 1] = 0;
			fill_m(0, y + 1);
		}
		else
			fill_m(x, y);
	}
	else if ((x < n - 1) && (y == n - 1))
	{
		if (check_char_column(x) && check_requests_column(x))
		{
			m[x + 1][y] = 0;
			fill_m(x + 1, y);
		}
		else
			fill_m(x, y);
	}
	else if ((x == n - 1) && (y == n - 1))
	{
		if (check_char_row(y) && check_char_column(x) && check_requests_row(y)
				&& check_requests_column(x))
		{
			flag = 1;
			return ;
		}
		else
			fill_m(x, y);
	}
	else
	{
		m[x + 1][y] = 0;
		fill_m(x + 1, y);
	}
}
*/
void	fill_m(int x, int y)
{
	if ((x == n - 1) && (y < n - 1))
	{
		while (m[x][y] < n && flag == 0)
		{
			m[x][y]++;
			if (check_char_row(y) && check_requests_row(y))
			{
				m[0][y + 1] = 0;
				fill_m(0, y + 1);
			}
		}
	}
	else if ((x < n - 1) && (y == n - 1))
	{
		while (m[x][y] < n && flag == 0)
		{
			m[x][y]++;
			if (check_char_column(x) && check_requests_column(x))
			{
				m[x + 1][y] = 0;
				fill_m(x + 1, y);
			}
		}
	}
	else if ((x == n - 1) && (y == n - 1))
	{
		while (m[x][y] < n && flag == 0)
		{
			m[x][y]++;
			if (check_char_row(y) && check_char_column(x) && 
					check_requests_row(y) && check_requests_column(x))
			{
				flag = 1;
				print();
				return ;
			}
		}
	}
	else
	{
		while (m[x][y] < n && flag == 0)
		{
			m[x][y]++;
			m[x + 1][y] = 0;
			fill_m(x + 1, y);
		}
	}
}

int		main(int argc, char **argv)
{
/*	if (check_input(argc, argv) == 0)
		write(2, "errore di input", 15);*/
	n = argv[1][0] - '0';
	if ((r = malloc(4 * n * sizeof(int))) == 0)
	{
		printf("errore nella allocazione di r");
		return (1);
	}
	if ((m = malloc(n * sizeof(int *))) == 0)
	{
		printf("errore nella allocazione di m");
		return (1);
	}
	if (!initialize_m())
		return (1);
	fill_r(argv[2]);
	flag = 0;
	fill_m(0, 0);
	if (flag == 0)
		printf("errore nella risoluzione");
	free_m();
	return (0);
}
