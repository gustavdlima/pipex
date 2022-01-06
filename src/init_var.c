/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:29:44 by gusalves          #+#    #+#             */
/*   Updated: 2022/01/05 21:13:48 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void start_struct(char **argv, char **envp, t_pipx *pipx)
{
	pipx->infile = argv[1];
	pipx->cmd1 = argv[2];
	pipx->cmd2 = argv[3];
	pipx->outfile = argv[4];
	pipx->envp = envp;
}
