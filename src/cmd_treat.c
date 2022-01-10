/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_treat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:49:23 by gusalves          #+#    #+#             */
/*   Updated: 2022/01/10 21:48:20 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**cmd_treat(char **cmd_matrix)
{
	int	i;
	int	j;
	int	count_first_arg;

	i = 0;
	count_first_arg = 0;
	while (cmd_matrix[i])
	{
		j = 0;
		if (cmd_matrix[2][j] == 39)
		{
			while (cmd_matrix[1][count_first_arg])
				count_first_arg++;
			cmd_matrix[2] = size_treat(cmd_matrix[1],
					cmd_matrix[2], count_first_arg);
			break ;
		}
		i++;
	}
	return (cmd_matrix);
}
