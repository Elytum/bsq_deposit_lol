#ifndef BSQ_H
# define BSQ_H

void	ft_put_analyse(int *analyse, int length);
int		ft_map_error(void);
void	map_error_exit(void);
void	ft_open_error(const char *str);
void	create_error(char *str);
int		get_length(char *str, int *length, int skip);
int 	get_intro_2(const char *str, int *nb, int skip, int pattern[6]);
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
