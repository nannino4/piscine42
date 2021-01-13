/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcefalo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 15:21:56 by gcefalo           #+#    #+#             */
/*   Updated: 2020/12/03 17:42:30 by gcefalo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		equal_char_check(char *base)
{
	int i;
	int j;
	int flag;

	flag = 1;
	i = 0;
	while (base[i])
	{
		j = i;
		while (base[++j])
		{
			if (base[j] == base[i])
				flag = 0;
		}
		i++;
	}
	return (flag);
}

int		base_control(char *base, int *length)
{
	int i;

	while (base[*length])
		*length = *length + 1;
	if (*length < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] < 32 || base[i] > 126)
			return (0);
		i++;
	}
	if (equal_char_check(base) == 0)
		return (0);
	return (1);
}

int		check(char c, char *base, int length, int *base_pos)
{
	int i;

	if (c == 32 || (c >= 9 && c <= 13))
		return (0);
	if (c == '+' || c == '-')
		return (1);
	i = 0;
	while (i < length)
	{
		if (c == base[i])
		{
			*base_pos = i;
			return (2);
		}
		i++;
	}
	return (3);
}

int		create_n(char *str, char *base, int *sign, int length)
{
	int n;
	int flag;
	int i;
	int base_pos;

	n = 0;
	flag = 0;
	i = -1;
	while (str[++i] && flag < 3)
	{
		if (check(str[i], base, length, &base_pos) >= flag)
		{
			flag = check(str[i], base, length, &base_pos);
			if (flag == 1 && str[i] == '-')
				*sign = *sign + 1;
			if (flag == 2)
			{
				n *= length;
				n += base_pos;
			}
		}
		else
			flag = 3;
	}
	return (n);
}

int		ft_atoi_base(char *str, char *base)
{
	int length;
	int sign;
	int n;

	length = 0;
	sign = 0;
	if (base_control(base, &length) == 0)
		return (0);
	n = create_n(str, base, &sign, length);
	if (sign % 2 == 1)
		n *= -1;
	return (n);
}
