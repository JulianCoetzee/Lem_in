#ifndef LEMIN_H
# define LEMIN_H

# define VISITED 1
# define UNVISITED 0
# define EMPTY 0

# include "../libft/libft.h"

typedef struct  s_room
{
char            *name;
int             start;
// int             end;
// int				r_nbr;
// int				visit_check;
// int				q_path;
int             x;
int             y;
int             len;
// struct s_links	*links_pf;
// struct s_room	*tmp_room;
// struct s_room	*path;
// struct s_room	*end_r;
// struct s_room	*start_r;
struct s_room   **links;
struct s_room   *next;
struct s_room   *prev;
}               t_room;

typedef struct s_move
{
    char		*room;
	int			ant;
}               t_move;

// typedef struct  s_links
// {
//     int             from_room;
//     int             to_room;
//     struct s_links  *next;
// }               t_links;

typedef struct  s_march
{
    int			i;
	int			path_size_sum;
	int			route_total;
	int			ant_total;
	int			*ants;
	int			*path_sizes;
}               t_march;

// void			enter_room(t_room *s_room, int room_nbr);
// void            exit_room(t_room *s_room, int room_nbr);
void			pathfinder(char ***all_paths, t_room *room);
char			**pathfiller(t_room *room);
char			***paths_found(t_room *rooms);
char			**get_paths(t_room *room);
int				all_paths(t_room *room);
char			**path_checker(t_room *room);
// void    		get_paths(t_room *s_room, int moves, int *room, int len);
// void			pathfinder(t_room *s_room);
void            add_links(t_room ***tmp_links, t_room ***set_links, t_room **door, int array_size);
t_room          *add_room(t_room **map);
int             check_co_ords(char **arr);
int				visit_check(t_room *s_room, int room_nbr);
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
void            move_out(t_move *move, int paths);
t_room          *new_room(void);
int		        validate_line(t_room **map, char *line, int *start, int *end);
int             valid_format(t_room **map, char *line, int *start, int *end);

#endif