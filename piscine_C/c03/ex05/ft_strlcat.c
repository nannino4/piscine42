/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcefalo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:47:11 by gcefalo           #+#    #+#             */
/*   Updated: 2020/12/01 13:28:02 by gcefalo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (dest[i] != 0)
		i++;
	j = 0;
	while (src[j] != 0)
	{
		if (i + j < size - 1)
			dest[j + i] = src[j];
		j++;
	}
	if (j + i < size - 1)
		dest[j + i] = 0;
	else if (i > size - 1)
	{
	}
	else
		dest[size - 1] = 0;
	return (i + j);
}
