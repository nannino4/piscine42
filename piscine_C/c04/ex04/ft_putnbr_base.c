/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcefalo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 09:59:53 by gcefalo           #+#    #+#             */
/*   Updated: 2020/12/03 19:09:44 by gcefalo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		equal_char_check(char *base)
{
	int i;
	int j;
	int flag;

	flag = 1;
	i = 0;
	while (base[i])
	{
		j = i;
		while (base[++j])
		{
			if (base[j] == base[i])
				flag = 0;
		}
		i++;
	}
	return (flag);
}

int		base_control(char *base, int *length)
{
	int i;

	i = 0;
	while (base[*length])
		*length = *length + 1;
	if (*length < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] < 32 || base[i] > 126)
			return (0);
		i++;
	}
	if (equal_char_check(base) == 0)
		return (0);
	return (1);
}

void	print(int n, char *base, int length)
{
	if (n <= -length)
	{
		write(1, "-", 1);
		print(n / -length, base, length);
		n = n % -length;
		print(-n, base, length);
	}
	else if (n > -length && n < 0)
	{
		write(1, "-", 1);
		write(1, &base[-n], 1);
	}
	else if (n >= length)
	{
		print(n / length, base, length);
		print(n % length, base, length);
	}
	else if (n >= 0 && n < length)
	{
		write(1, &base[n], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int length;
	int i;

	length = 0;
	if ((i = base_control(base, &length)) == 0)
		return ;
	print(nbr, base, length);
}
