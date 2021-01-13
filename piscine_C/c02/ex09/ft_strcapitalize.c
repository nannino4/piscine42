/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcefalo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 11:04:38 by gcefalo           #+#    #+#             */
/*   Updated: 2020/11/30 12:31:37 by gcefalo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check(char *str, int i)
{
	int check;

	check = 0;
	if (str[i] >= '0' && str[i] <= '9')
		check = 1;
	if (str[i] >= 'A' && str[i] <= 'Z')
		check = 2;
	if (str[i] >= 'a' && str[i] <= 'z')
		check = 3;
	return (check);
}

char	*ft_strcapitalize(char *str)
{
	int i;
	int up_case;

	i = 0;
	up_case = 1;
	while (str[i] != 0)
	{
		if (check(str, i) == 0)
		{
			up_case = 1;
		}
		else
		{
			if (up_case == 0 && check(str, i) == 2)
				str[i] += 32;
			if (up_case && check(str, i) == 3)
				str[i] -= 32;
			up_case = 0;
		}
		i++;
	}
	return (str);
}
