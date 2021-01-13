/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcefalo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:02:41 by gcefalo           #+#    #+#             */
/*   Updated: 2020/12/01 10:36:03 by gcefalo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				flag;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != 0 && s2[i] != 0 && i < n)
	{
		i++;
	}
	if (i == n || s1[i] == s2[i])
		flag = 0;
	else if (s1[i] > s2[i])
		flag = 1;
	else
		flag = -1;
	return (flag);
}
