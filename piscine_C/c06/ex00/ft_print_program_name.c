/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcefalo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 13:00:35 by gcefalo           #+#    #+#             */
/*   Updated: 2020/12/09 11:41:04 by gcefalo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int		main(int argc, char *argv[])
{
	int i;

	if (argc > 0)
	{
		i = 0;
		while (i < ft_strlen(argv[0]))
		{
			write(1, &argv[0][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
