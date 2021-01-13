/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcefalo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 09:58:26 by gcefalo           #+#    #+#             */
/*   Updated: 2020/11/28 16:52:16 by gcefalo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char *arr, int n)
{
	int		counter;
	char	tmp[10];

	counter = n - 1;
	while (counter >= 0)
	{
		tmp[counter] = arr[counter];
		tmp[counter] += 48;
		write(1, &tmp[counter], 1);
		counter--;
	}
	if (arr[n - 1] != 10 - n)
		write(1, ", ", 2);
}

void	ft_recursive(char *arr, int n)
{
	int decimal_place;
	int decimal_place2;

	ft_print(arr, n);
	if (arr[n - 1] == 10 - n)
		return ;
	decimal_place = 0;
	while (decimal_place < n)
	{
		if (arr[decimal_place] == 9 - decimal_place)
			decimal_place++;
		else
		{
			decimal_place2 = decimal_place;
			decimal_place = n;
		}
	}
	arr[decimal_place2]++;
	while (decimal_place2 > 0)
	{
		arr[decimal_place2 - 1] = arr[decimal_place2] + 1;
		decimal_place2--;
	}
	ft_recursive(arr, n);
}

void	ft_print_combn(int n)
{
	char	arr[10];
	int		i;

	i = 0;
	while (i < n)
	{
		arr[i] = n - i - 1;
		i++;
	}
	ft_recursive(arr, n);
}
