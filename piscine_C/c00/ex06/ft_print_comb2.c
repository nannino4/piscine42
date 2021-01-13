/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcefalo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:22:11 by gcefalo           #+#    #+#             */
/*   Updated: 2020/11/26 12:32:07 by gcefalo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char a1, char b1, char a2, char b2)
{
	write(1, &a1, 1);
	write(1, &b1, 1);
	write(1, " ", 1);
	write(1, &a2, 1);
	write(1, &b2, 1);
	if (!(a1 == '9' && b1 == '8' && a2 == '9' && b2 == '9'))
		write(1, ", ", 2);
}

void	ft_loop(char a1, char b1, char a2, char b2)
{
	while (a1 <= '9')
	{
		b1 = '0';
		while (b1 <= '9')
		{
			a2 = a1;
			b2 = b1 + 1;
			while (a2 <= '9')
			{
				while (b2 <= '9')
				{
					ft_print(a1, b1, a2, b2);
					b2++;
				}
				a2++;
				b2 = '0';
			}
			b1++;
		}
		a1++;
	}
}

void	ft_print_comb2(void)
{
	char a1;
	char b1;
	char a2;
	char b2;

	a1 = '0';
	b1 = '0';
	a2 = '0';
	b2 = '1';
	ft_loop(a1, b1, a2, b2);
}
