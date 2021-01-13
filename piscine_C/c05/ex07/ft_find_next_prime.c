/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcefalo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:39:23 by gcefalo           #+#    #+#             */
/*   Updated: 2020/12/08 18:03:15 by gcefalo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int i;

	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	i = 2;
	while (i <= (nb / 2))
	{
		if ((nb % i) == 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	int i;

	if (nb <= 2)
		return (2);
	i = nb;
	while (i <= 2147483647)
	{
		if (ft_is_prime(i))
			return (i);
		i++;
	}
	return (0);
}
