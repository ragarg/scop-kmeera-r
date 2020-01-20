/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <kmeera-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:00:27 by kmeera-r          #+#    #+#             */
/*   Updated: 2020/01/17 17:12:32 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

float	ft_atof(const char *number)
{
	float	n;
	float	n2;
	int		i;

	return (atof(number));
	n = ft_atoi(number);
	i = 0;
	while (number[i])
	{
		if (number[i] == '.')
		{
			n2 = ft_atoi(number + 1 + i);
			while (n2 > 1)
				n2 /= 10;
			if (n < 0)
				return (n - n2);
			return (n + n2);
		}
		i++;
	}
	return (n);
}
