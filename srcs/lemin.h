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
    /* data */
}               t_move;

typedef struct s_output
{
    /* data */
}               t_output;

void            add_links(t_room ***tmp_links, t_room ***set_links, t_room **door, int array_size);
t_room          *add_room(t_room **map);
int             check_co_ords(char **arr);
void            command_check(t_room **room, int *start, int *end);
void            del_room(t_room **map);
int             duplicate_coordinates(t_room **map);
int             duplicate_name(t_room **map);
void	        error_out(int errtype);
void            free_array(char **arr);
void            free_link_array(t_room **links);
void            free_links(t_room *room);
void            free_map(t_room **map);
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

#endif