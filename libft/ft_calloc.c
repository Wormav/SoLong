/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:58:41 by jlorette          #+#    #+#             */
/*   Updated: 2024/08/08 16:51:41 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t element_count, size_t element_size)
{
	void	*result;

	if (element_size && element_count * element_size / element_size
		!= element_count)
		return (NULL);
	result = malloc(element_count * element_size);
	if (!result)
		return (NULL);
	ft_bzero(result, element_count * element_size);
	return (result);
}
