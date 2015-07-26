/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 02:55:27 by achazal           #+#    #+#             */
/*   Updated: 2015/07/26 02:55:29 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

#include <sys/types.h>

void	ft_put_analyse(int *analyse, int length);
int		ft_map_error(void);
void	create_error(char *str);
int		solve_error_loop(int fd, char *tmp, int *analyse);
int		get_length(char *str, int *length, int skip);
int		get_intro_2(const char *str, int *nb, int skip, int pattern[6]);
int		get_intro(const char *str, int *nb, int *skip, int pattern[6]);
int		solve(int fd, int length, int pattern[6], int nb);
void	put_solution(int fd, int solution[6], int length, int nb);
void	solve_map(char *path);
void	ft_tell_path(const char *str);
void	ft_tell_intro(int nb);
void	ft_tell_intro_2(int nb, int pattern[6]);
void	ft_tell_length(int nb);
void	ft_tell_solution(int solution[3]);
int		prepare_fd_skip(char *str, int skip);
char	*ft_safe_malloc(size_t length);
void	put_file_path(char *str);
void	generate_map(void);

#endif
