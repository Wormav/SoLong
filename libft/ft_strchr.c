/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:30:08 by jlorette          #+#    #+#             */
/*   Updated: 2024/08/06 14:55:59 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	target;
	size_t			i;

	target = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == target)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == target)
		return ((char *)&s[i]);
	return (NULL);
}
