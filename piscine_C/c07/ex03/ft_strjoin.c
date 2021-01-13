/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcefalo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 19:00:21 by gcefalo           #+#    #+#             */
/*   Updated: 2020/12/09 19:35:58 by gcefalo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

void	count_len(char **strs, int size, int *len)
{
	int		i;

	i = 0;
	while (i < size)
	{
		*len += ft_strlen(strs[i]);
		i++;
	}
}

void	fill_arr(char *arr, char **strs, char *sep, int size)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	j = 0;
	while (i < size)
	{
		while (strs[i][j])
		{
			arr[k++] = strs[i][j++];
		}
		j = 0;
		while (sep[j] && i < (size - 1))
		{
			arr[k] = sep[j];
			k++;
			j++;
		}
		j = 0;
		i++;
	}
	arr[k] = 0;
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*arr;
	int		len;

	if (size == 0)
	{
		arr = malloc(sizeof(char));
		arr[0] = 0;
		return (arr);
	}
	len = 0;
	count_len(strs, size, &len);
	arr = malloc((len + ((size - 1) * ft_strlen(sep)) + 1) * sizeof(char));
	fill_arr(arr, strs, sep, size);
	return (arr);
}
