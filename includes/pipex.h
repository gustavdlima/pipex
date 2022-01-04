/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:57:50 by gusalves          #+#    #+#             */
/*   Updated: 2022/01/04 23:13:14 by gusalves         ###   ########.fr       */
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

# define PATH "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"

// start function
void	pipex(char **argv, char **envp);

// proc functions
void	child_proc(char **argv, char **envp, int *fd);
void	parent_proc(char **argv, char **envp, int *fd);

// cmd exec funtion
void	cmd_exec(char *argv, char **envp);

// find path function
char	*find_path(char *command);

// utils
void	free_matrix(char **path);
char	*strjoin_free(char *s1, char const *s2);

#endif
