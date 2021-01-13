/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcefalo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 19:22:47 by gcefalo           #+#    #+#             */
/*   Updated: 2020/11/30 10:53:05 by gcefalo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		if (src[i] == 0)
		{
			while (i < n)
			{
				dest[i] = 0;
				i++;
			}
		}
		else
			dest[i] = src[i];
		i++;
	}
	return (dest);
}
