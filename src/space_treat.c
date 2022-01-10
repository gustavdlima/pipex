/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_treat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:50:51 by gusalves          #+#    #+#             */
/*   Updated: 2022/01/10 20:58:05 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**reverse_space_treat(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == '`')
			{
				matrix[i][j] = ' ';
			}
			j++;
		}
		i++;
	}
	return (matrix);
}

char	*space_treat(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == 39)
		{
			i++;
			while (cmd[i] != 39)
			{
				if (cmd[i] == ' ')
					cmd[i] = '`';
				i++;
			}
		}
		i++;
	}
	return (cmd);
}