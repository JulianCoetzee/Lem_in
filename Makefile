NAME = lem-in

LIB_PATH = ./libft/

FLAGS = -Wall -Werror -Wextra

SRCS_PATH = ./srcs/

OBJS_PATH = ./objs/

OBJS_DIR = objs

LEM-IN_SRCS = $(NAME).c\

LEM-IN_C = $(addprefix $(OBJS_PATH), $(LEM-IN_SRCS))

LEM-IN_O = $(patsubst %.c, %.o, $(LEM-IN_C))

all: $(NAME)

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

libft:
	@$(MAKE) -C $(LIB_PATH)/

$(NAME): $(OBJS_DIR) $(LEM-IN_O) libft
	@gcc $(FLAGS) $(LEM-IN_O) -L $(LIB_PATH) -lft -o $(NAME)
	@echo "$(NAME_1) created"

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

re: fclean all

.PHONY: all clean fclean libft re