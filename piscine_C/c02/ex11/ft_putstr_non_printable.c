/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcefalo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 15:04:49 by gcefalo           #+#    #+#             */
/*   Updated: 2020/11/30 16:43:36 by gcefalo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	dec_to_exa(int n)
{
	char c;

	write(1, "\\", 1);
	c = '0' + n / 16;
	write(1, &c, 1);
	if (n % 16 <= 9)
	{
		c = '0' + (n % 16);
		write(1, &c, 1);
	}
	else
	{
		c = 'a' + (n % 16) - 10;
		write(1, &c, 1);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] >= 32)
		{
			write(1, &str[i], 1);
		}
		else
		{
			dec_to_exa(str[i]);
		}
		i++;
	}
}
