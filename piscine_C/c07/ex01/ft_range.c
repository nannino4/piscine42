/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcefalo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 10:11:56 by gcefalo           #+#    #+#             */
/*   Updated: 2020/12/08 10:23:15 by gcefalo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*arr;
	int		i;
	int		tmp;

	if (min >= max)
		return (0);
	arr = malloc((max - min) * 4);
	i = 0;
	tmp = min;
	while (i < (max - min))
	{
		arr[i] = tmp;
		tmp++;
		i++;
	}
	return (arr);
}
