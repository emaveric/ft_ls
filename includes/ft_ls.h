/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:23:13 by mplutarc          #+#    #+#             */
/*   Updated: 2019/12/25 15:55:35 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# define ERROR -1

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <time.h>
# include <grp.h>
# include <dirent.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct		s_column
{
	int				max_ino;
	int				max_link;
	int				max_size;
	int				max_uid;
	int				max_gid;
	char			*str_link;
	char			*str_size;
	char			*str_ino;
	char			*str_uid;
	char			*str_gid;
}					t_column;

struct				s_node
{
	int				ino;
	int				size;
	int				links;
	int				ind;
	char			*str_link;
	char			*uid;
	char			*gid;
	char			*mode;
	int				flag;
	char			*time;
	long int		sec;
	char			*field;
	struct s_node	*left;
	struct s_node	*right;
};

typedef struct		s_ls
{
	int				l;
	int				i;
	int				a;
	int				t;
	int				r;
	int				ac;
	int				big_r;
	int				flag;
	int				point;
	long int		sec;
	int				blocks;
	int				f_sum;
	int				dh_index;
	int				*f_index;
	t_column		*col;
}					t_ls;

int					files(char *str, char *the_dir);
int					directory(char *the_dir, t_ls *ls);
int					main(int ac, char **av);
int					validation(int ac, char **av, t_ls *ls);
int					sorting(int ac, char **av, t_ls *ls, struct stat buf);
int					dhyp_check(int ac, char **av, t_ls *ls);
void				print(struct s_node *tree, t_ls *ls);
void				e_print(struct s_node *tree, t_ls *ls);
int					output(t_ls *ls, struct s_node *tree);
void				find_flag(t_ls *ls, char **av, int i);
struct s_node		*addnode(char *str, struct s_node *tree, struct stat buf,
							t_ls *ls);
void				big_r_flag_print(struct s_node *tree, t_ls *ls);
struct s_node		*addnode_flag_r(char *str, struct s_node *tree,
									struct stat buf, t_ls *ls);
void				l_flag_print(struct s_node *tree, t_ls *ls);
void				i_flag_print(struct s_node *tree, t_ls *ls);
int					mode_to_rwx(struct s_node *tree, struct stat buf);
struct s_node		*tree_create(char *str, struct stat buf, t_ls *ls);
struct s_node		*addnode_flag_t(char *str, struct s_node *tree,
									struct stat buf, t_ls *ls);
void				free_tree(struct s_node *tree);
void				free_ls(t_ls *ls);
void				free_first_tree(struct s_node *tree);
void				into_string(struct s_node *tree, t_ls *ls);
t_column			*init_col(void);
t_ls				*itostr(struct s_node *tree, t_ls *ls);
void				max_len(struct s_node *tree, t_ls *ls);
int					valid_error(int ac, char **av);
struct s_node		*tree_create(char *str, struct stat buf, t_ls *ls);
void				ft_error(char *the_dir);

#endif
