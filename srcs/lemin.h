#ifndef LEMIN_H
# define LEMIN_H
# include "../libft/libft.h"

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

void            add_links(t_room ***tmp_links, t_room ***set_links, t_room **door, int array_size);
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
void            move_out(t_move *move, int paths);
t_room          *new_room(void);
int		        validate_line(t_room **map, char *line, int *start, int *end);
int             valid_format(t_room **map, char *line, int *start, int *end);
//marchy
void			free_int_array(int **array);
void			free_march_array(t_march *march);
void			move_ant(char ***route, int i_ant);
void    		sep_ant(t_march *march);
int				route_quan(int n, int *dist);
void			free_route(char ****route_loc);
//movey single
void			sing_route(char **route, int i_ant, int dist);
void			ant_turn(t_move *move, int i, int dist);
t_move			*make_move(char **route, int dist);
void			put_move(t_move *move, int dist);
//movey multo
void			multi_route(char ***route, t_march *march);
void			put_iter(t_march *march, t_move **moves);
void			turn_iter(t_march *march, t_move **moves);
int				turn_quan(t_march *march);
//path testing ish
int				st_maxpaths(t_room *rooms);
void			st_pathclear(t_room *rooms);
void			st_findpaths(char ***paths, t_room *rooms);
char			***ft_pathfind(t_room *rooms);
//void			ft_printpath(char ***paths);
// char			**ft_path(t_room *room);
char			**ft_excl_path(t_room *room);
char			**ft_minpath(t_room *rooms);


#endif