/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:56:12 by jules             #+#    #+#             */
/*   Updated: 2020/05/18 12:22:27 by jules            ###   ########.fr       */
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
	int			route_dist_tot;
	int			route_tot;
	int			ant_tot;
	int			*ants;
	int			*dist;
}               t_march;

//duplicate_check.c
int             duplicate_coordinates(t_room **map);
int             duplicate_name(t_room **map);
int             is_duplicate(t_room **map);
//error.c
void	        error_out(int errtype);
//freedom.c
void            free_array(char **arr);
void            free_int_array(int **arr);
void            free_link_array(t_room **links);
void            free_links(t_room *room);
void            free_map(t_room **map);
//freedomII.c
void            free_move(t_move **move);
void            free_move_array(t_move ***moves);
void			free_route(char ****route_loc);
//i_dont_walk_alone.c
void			multi_route(char ***route, t_march *march);
//i_walk_alone.c
t_move			*make_move(char **route, int dist);
void			ant_turn(t_move *move, int i, int dist);
void			put_move(t_move *move, int dist);
void			sing_route(char **route, int i_ant, int dist);
//king_jul.c
void			move_ant(char ***route, int i_ant);
//link_check.c
int             ft_links(t_room **map, char *line);
int             link_split(t_room **map, char *line);
//links.c
void            add_links(t_room ***tmp_links, t_room ***set_links,
							t_room **door, int array_size);
int             link_array(t_room **room, t_room **door);			
//pathfinder.c
char			***paths_found(t_room *rooms);
char			**path_checker(t_room *room);
int				all_paths(t_room *room);
void			pathfinder(char ***all_paths, t_room *room);
//paths.c
char			**get_paths(t_room *rooms);
//reader.c
int             get_ants(void);
void            get_map(t_room **map);
//room_check.c
int             check_co_ords(char **arr);
void            command_check(t_room **room, int *start, int *end);
int             ft_rooms(t_room **map, char **arr, int *start, int *end);
//rooms.c
t_room          *add_room(t_room **map);
t_room          *new_room(void);
void            del_room(t_room **map);
//two_roads_div.c
int				route_quan(int n, int *dist);
void    		sep_ant(t_march *march);
//validate_input.c
int             valid_format(t_room **map, char *line, int *start, int *end);
int		        validate_line(t_room **map, char *line, int *start, int *end);
//zombo_iteration.c
void			put_iter(t_march *march, t_move **moves);
void			turn_iter(t_march *march, t_move **moves);
int				turn_quan(t_march *march);

#endif