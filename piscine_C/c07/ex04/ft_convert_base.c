/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcefalo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:51:15 by gcefalo           #+#    #+#             */
/*   Updated: 2020/12/10 10:42:31 by gcefalo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		equal_char_check(char *base);

int		base_control(char *base, int *length);

int		check(char c, char *base, int length, int *base_pos);

int		create_n(char *str, char *base, int *sign, int length);

void	create_arr(char *arr, int n, char *base, int length);

void	toomanyrows(char *tmp, int n, char *base)
{
	while (*tmp)
		tmp++;
	*tmp = base[n];
	*(++tmp) = 0;
}

int		ft_itoa_base(char *arr, int nbr, char *base)
{
	int		length;

	length = 0;
	if (base_control(base, &length) == 0)
		return (0);
	create_arr(arr, nbr, base, length);
	return (1);
}

int		ft_atoi_base(char *str, char *base, int *flag)
{
	int length;
	int sign;
	int n;

	length = 0;
	sign = 0;
	if (base_control(base, &length) == 0)
		*flag = 0;
	n = create_n(str, base, &sign, length);
	if (sign % 2 == 1)
		n *= -1;
	return (n);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		n;
	char	*arr;
	int		flag;

	flag = 1;
	arr = malloc(1000 * sizeof(char));
	n = ft_atoi_base(nbr, base_from, &flag);
	if (flag == 0)
		return (0);
	*arr = 0;
	if (ft_itoa_base(arr, n, base_to) == 0)
		return (0);
	return (arr);
}
