
#include "lemin.h"

// check for: open lines, (##)both command lines, (#)comment line
// checks line format with valid_format

int 		validate_line(t_room **map, char *line, int *start, int *end)
{
	int         valid;
	static int  command_line;

	if (line[0] == '\0')
		return (0);
	else if (line[0] == '#' && line[1] == '#')
	{
		if (command_line == 1)
			return (0);
		if (ft_strcmp(line, "##start") == 0)
			*start = *start + 1;
		if (ft_strcmp(line, "##end") == 0)
			*end = *end + 1;
		command_line = 1;
		return (1);
	}
	else if (line[0] == '#' && line[1] != '#')
		return (1);
	else
	{
		valid = valid_format(map, line, start, end);
		command_line = 0;
		return (valid);
	}
}
static int		not_valid(char **array)
{
	free_array(array);
	return (0);
}
// splits read line into array
// count array size (1 = link, 3 = room), error if not
// checks valid sizes with further functions

int				 valid_format(t_room **map, char *line, int *start, int *end)
{
	char        **arr;
	int         i;
	static int  link;

	arr = ft_strsplit(line, ' ');
	i = 0;
	link = 0;
	while (arr[i] != NULL)
		i++;
	if (i != 1 && i != 3)
		not_valid(arr);
	else if (i == 3)
	{
		if (!ft_rooms(map, arr, start, end) || link == 1)
			return (0);
	}
	else if (i == 1)
	{
		link = 1;
		free_array(arr);
		return (ft_links(map, line));
	}
	return (1);
}