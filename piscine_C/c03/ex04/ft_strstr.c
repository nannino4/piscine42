/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcefalo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:09:04 by gcefalo           #+#    #+#             */
/*   Updated: 2020/12/01 12:42:20 by gcefalo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i[2];
	int k;
	int position;

	position = -1;
	i[0] = 0;
	while (to_find[i[0]] != 0)
		i[0]++;
	i[1] = 0;
	while (str[i[1]] != 0 && i[1] != -1)
	{
		k = 0;
		while (str[i[1] + k] == to_find[k] && str[i[1] + k] != 0 && k < i[0])
			k++;
		if (k == i[0])
		{
			position = i[1];
			i[1] = -2;
		}
		i[1]++;
	}
	if (position < 0)
		return (0);
	else
		return (str + position);
}
