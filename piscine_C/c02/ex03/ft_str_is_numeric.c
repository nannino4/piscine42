/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcefalo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 19:52:45 by gcefalo           #+#    #+#             */
/*   Updated: 2020/11/29 20:02:52 by gcefalo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_numeric(char *str)
{
	int flag;
	int i;

	i = 0;
	flag = 1;
	while (str[i] != 0)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			flag = 0;
		}
		i++;
	}
	return (flag);
}
