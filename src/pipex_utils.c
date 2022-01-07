/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:59:00 by gusalves          #+#    #+#             */
/*   Updated: 2022/01/07 21:03:19 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	errors(char *string, int num)
{
	write(2, string, ft_strlen(string));
	exit(num);
}

char	**reverse_space_treat(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	while(matrix[i])
	{
		j = 0;
		while(matrix[i][j])
		{
			if (matrix[i][j] == 39)
			{
				j++;
				while (matrix[i][j] != 39)
				{
					if (matrix[i][j] == ';')
						matrix[i][j] = ' ';
					j++;
				}
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
	while(cmd[i])
	{
		if (cmd[i] == 39)
		{
			i++;
			while (cmd[i] != 39)
			{
				if (cmd[i] == ' ')
					cmd[i] = ';';
				i++;
			}
		}
		i++;
	}
	return (cmd);
}

void	free_matrix(char **path)
{
	int	i;

	i = 0;
	while (path[i] != NULL)
	{
		free(path[i]);
		i++;
	}
	free(path);
}

char	*strjoin_free(char *s1, char const *s2)
{
	char	*nstring;
	size_t	i;
	size_t	a;

	nstring = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	a = 0;
	if (nstring == 0)
		return (0);
	while (s1[i] != '\0')
	{
		nstring[i] = s1[i];
		i++;
	}
	while (s2[a] != '\0')
	{
		nstring[i + a] = s2[a];
		a++;
	}
	nstring[i + a] = '\0';
	free(s1);
	s1 = NULL;
	return (nstring);
}
