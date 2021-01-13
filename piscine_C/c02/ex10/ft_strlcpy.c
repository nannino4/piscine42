/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcefalo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:32:12 by gcefalo           #+#    #+#             */
/*   Updated: 2020/12/01 10:37:30 by gcefalo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (src[i] != 0)
	{
		if (i < size - 1)
		{
			dest[i] = src[i];
		}
		i++;
	}
	if (i < size - 1)
		dest[i] = 0;
	else
		dest[size - 1] = 0;
	return (i);
}
