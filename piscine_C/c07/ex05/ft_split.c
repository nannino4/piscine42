/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcefalo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 19:03:27 by gcefalo           #+#    #+#             */
/*   Updated: 2020/12/09 20:13:12 by gcefalo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		check(char c, char *charset)
{
	int		i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (0);
		i++;
	}
	return (1);
}

int		count_words(char *str, char *charset)
{
	int		words;
	int		flag;
	int		i;

	words = 0;
	flag = 0;
	i = 0;
	while (str[i])
	{
		if (check(str[i], charset) == 1)
		{
			if (flag == 0)
				words++;
			flag = 1;
		}
		else
			flag = 0;
		i++;
	}
	return (words);
}

void	assign_len(int *len, char *str, char *charset)
{
	int		i;
	int		j;
	int		flag;

	flag = 0;
	j = 0;
	i = 0;
	while (str[i])
	{
		if (check(str[i], charset) == 1)
		{
			len[j]++;
			flag = 1;
		}
		else
		{
			if (flag == 1)
				j++;
			flag = 0;
		}
		i++;
	}
}

void	fill_arr(char **arr, char *str, char *charset)
{
	int		i;
	int		j;
	int		k;
	int		flag;

	flag = 0;
	j = 0;
	k = 0;
	i = -1;
	while (str[++i])
	{
		if (check(str[i], charset) == 1)
		{
			arr[j][k++] = str[i];
			flag = 1;
		}
		else
		{
			if (flag-- == 1)
			{
				arr[j++][k] = 0;
				k = 0;
			}
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		i;
	int		*len;

	arr = malloc((count_words(str, charset) + 1) * sizeof(char *));
	arr[count_words(str, charset)] = 0;
	len = malloc(count_words(str, charset) * sizeof(int));
	i = 0;
	while (i < count_words(str, charset))
		len[i++] = 0;
	assign_len(len, str, charset);
	i = 0;
	while (i < count_words(str, charset))
	{
		arr[i] = malloc((len[i] + 1) * sizeof(char));
		arr[i][len[i]] = 0;
		i++;
	}
	fill_arr(arr, str, charset);
	return (arr);
}
