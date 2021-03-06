NAME = lem-in

LIB_PATH = ./libft/

FLAGS = -Wall -Werror -Wextra

SRCS_PATH = ./srcs/

OBJS_PATH = ./objs/

OBJS_DIR = objs

LEMIN_SRCS = lemin.c\
				duplicate_check.c\
				error.c\
				freedom.c\
				freedomII.c\
				i_walk_alone.c\
				i_dont_walk_alone.c\
				king_jul.c\
				link_check.c\
				links.c\
				pathfinder.c\
				paths.c\
				reader.c\
				room_check.c\
				rooms.c\
				two_roads_div.c\
				validate_input.c\
				zombo_iteration.c\

LEMIN_C = $(addprefix $(OBJS_PATH), $(LEMIN_SRCS))

LEMIN_O = $(patsubst %.c, %.o, $(LEMIN_C))

all: $(NAME)

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

libft:
	@$(MAKE) -C $(LIB_PATH)/

$(NAME): $(OBJS_DIR) $(LEMIN_O) libft
	@gcc $(FLAGS) $(LEMIN_O) -L $(LIB_PATH) -lft -o $(NAME)
	@echo "$(NAME) created"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@gcc $(FLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIB_PATH)/ clean
	@rm -rf $(OBJS_DIR)
	@echo "objs deleted"

fclean:
	@$(MAKE) -C $(LIB_PATH)/ fclean
	@rm -rf $(OBJS_DIR)
	@echo "objs deleted"
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all clean

.PHONY: all clean fclean libft re