/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:56:12 by jules             #+#    #+#             */
/*   Updated: 2020/05/17 20:58:33 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "../libft/libft.h"
# define EMPTY 0
# define RESET 0

typedef struct  s_room
{
char            *name;
int             start;
int             x;
int             y;
int             len;
struct s_room   **links;
struct s_room   *next;
struct s_room   *prev;
}               t_room;

typedef struct s_move
{
    char		*room;
	int			ant;
}               t_move;

typedef struct  s_march
{
    int			i;
	int			path_size_sum;
	int			route_total;
	int			ant_total;
	int			*ants;
	int			*path_sizes;
}               t_march;

void            add_links(t_room ***tmp_links, t_room ***set_links,
								 t_room **door, int array_size);
t_room          *add_room(t_room **map);
int             check_co_ords(char **arr);
void            command_check(t_room **room, int *start, int *end);
void            del_room(t_room **map);
int             duplicate_coordinates(t_room **map);
int             duplicate_name(t_room **map);
void	        error_out(int errtype);
void            free_array(char **arr);
void            free_int_array(int **arr);
void            free_link_array(t_room **links);
void            free_links(t_room *room);
void            free_map(t_room **map);
void            free_move(t_move **move);
void            free_move_array(t_move ***moves);
int             ft_links(t_room **map, char *line);
int             ft_rooms(t_room **map, char **arr, int *start, int *end);
int             get_ants(void);
void            get_map(t_room **map);
int             is_duplicate(t_room **map);
int             link_array(t_room **room, t_room **door);
int             link_split(t_room **map, char *line);
t_room          *new_room(void);
int		        validate_line(t_room **map, char *line, int *start, int *end);
int             valid_format(t_room **map, char *line, int *start, int *end);

// pathfinding

char			**path_checker(t_room *room);
int				all_paths(t_room *room);
void			pathfinder(char ***all_paths, t_room *room);
char			***paths_found(t_room *rooms);
char			**get_paths(t_room *rooms);

//fail safe tests

int				path_count(char ***routes);
int				path_size(char **path);
int				*path_sizes(char ***routes, int route_total);
int 			path_size_sum(int *path_sizes);
int 			ant_routes_used(int ant_total, int *path_sizes);
void		    ant_march(char ***paths, int ant_total);
void    		single_file(char **path, int ant_total, int path_size);
void   			 ant_turn(t_move *move, int next_ant, int path_size);
void   			 ant_columns(t_march *move_out);
void   			 columns(char ***paths, t_march *move_out);
int    			 turn_total(t_march *move_out);
void   			 turn_loop(t_march *move_out, t_move **moves);
int    			 multi_move_check(t_move *move, int path_size);
void    		out_loop(t_march *move_out, t_move **moves);
t_move			*make_move(char **path, int path_size);
t_move			**make_moves(char ***path, int *path_sizes, int route_total);
void            move_output(t_move *move, int paths);
void    		free_paths(char ****paths_pointer);

#endif