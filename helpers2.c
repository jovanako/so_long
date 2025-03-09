/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                          :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:52:38 by jkovacev          #+#    #+#             */
/*   Updated: 2025/03/04 13:52:51 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*this_tile(char c)
{
	if (c == '0')
		return ("sprites/grass.xpm");
	else if (c == '1')
		return ("sprites/tree.xpm");
	else if (c == 'C')
		return ("sprites/mushrooms.xpm");
	else if (c == 'E')
		return ("sprites/exit.xpm");
	else if (c == 'P')
		return ("sprites/wizard.xpm");
	return (NULL);
}

int		count_c(char *s, char c, int len)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < len)
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

int  print_error_and_return(char *error_message, int n)
{
    perror(error_message);
    return (n);
}