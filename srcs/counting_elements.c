/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <kmeera-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:00:37 by kmeera-r          #+#    #+#             */
/*   Updated: 2020/01/17 18:03:21 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	counting_elements(const char *obj, int count[4])
{
	char	*line;
	int		fd;

	fd = open(obj, O_RDONLY);
	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	count[3] = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == 'v' && line[1] == 't' && line[2] == ' ')
			count[1] += 1;
		else if (line[0] == 'v' && line[1] == 'n' && line[2] == ' ')
			count[2] += 1;
		else if (line[0] == 'v' && line[1] == ' ')
			count[0] += 1;
		else if (line[0] == 'f' && line[1] == ' ')
			count[3] += 1;
	}
	close(fd);
}
