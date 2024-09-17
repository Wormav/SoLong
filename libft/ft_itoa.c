/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:28:43 by jlorette          #+#    #+#             */
/*   Updated: 2024/08/08 16:48:35 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_size(int n)
{
	int	size;
	int	is_neg;

	size = 0;
	is_neg = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		is_neg = 1;
	while (n)
	{
		size++;
		n = n / 10;
	}
	return (size + is_neg);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		size;
	long	nb;

	nb = n;
	size = ft_char_size(nb);
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	result[size] = '\0';
	if (nb < 0)
	{
		result[0] = '-';
		nb = nb * -1;
	}
	if (nb == 0)
		result[0] = '0';
	while (nb > 0)
	{
		size--;
		result[size] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (result);
}
