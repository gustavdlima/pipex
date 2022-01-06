/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:57:50 by gusalves          #+#    #+#             */
/*   Updated: 2022/01/05 23:42:34 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

# define PATH "/usr/local/sbin/:/usr/local/bin/:/usr/sbin/:/usr/bin/:/sbin/:/bin/"

typedef	struct	s_pipx {
	char	*infile;
	char	*outfile;
	char	*cmd1;
	char	*cmd2;
	char	**envp;
}				t_pipx;

// start functions
void start_struct(char **argv, char **envp, t_pipx *pipx);
void	pipex(t_pipx *pipx);

// proc functions
void	child_proc(int *fd, t_pipx *pipx);
void	parent_proc(int *fd, t_pipx *pipx);

// cmd exec funtion
void	cmd_exec(char *cmd, t_pipx *pipx);

// find path function
char	*find_path(char *cmd);

// utils
void	free_matrix(char **path);
char	*strjoin_free(char *s1, char const *s2);
char	*space_treat(char *cmd);

#endif
