/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcefalo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 18:54:16 by gcefalo           #+#    #+#             */
/*   Updated: 2020/12/10 08:41:04 by gcefalo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		i;
	int		tmp;

	if (min >= max)
	{
		range[0] = 0;
		return (0);
	}
	if ((range[0] = malloc((max - min) * 4)) == 0)
		return (-1);
	i = 0;
	tmp = min;
	while (i < (max - min))
	{
		range[0][i] = tmp;
		tmp++;
		i++;
	}
	return (max - min);
}
