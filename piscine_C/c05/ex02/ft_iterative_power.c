/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcefalo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 12:14:25 by gcefalo           #+#    #+#             */
/*   Updated: 2020/12/04 12:25:30 by gcefalo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int n_to_be_returned;

	n_to_be_returned = 1;
	if (power < 0)
		return (0);
	while (power > 0)
	{
		n_to_be_returned *= nb;
		power--;
	}
	return (n_to_be_returned);
}
