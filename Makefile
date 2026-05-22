# ==================== COLORS ====================
GREEN		= \033[0;32m
RED			= \033[0;31m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
RESET		= \033[0m
BOLD		= \033[1m

# ==================== NAMES ====================
NAME		= minishell
LIBFT		= libft/libft.a

# ==================== DIRECTORIES ====================
SRC_DIR		= src
OBJ_DIR		= obj
INCLUDE_DIR	= includes
LIBFT_DIR	= libft

# ==================== SOURCES ====================
SRCS		=	main.c \
				signals.c \
				lexer/lexer1.c \
				lexer/token1.c \
				lexer/operator1.c \
				lexer/norme1.c \
				expander/expander.c \
				parser/parser.c \
				executor/executor.c \
				executor/path.c \
				heredoc/heredoc.c \
				builtins/builtins.c \
				builtins/export.c \
				builtins/unset.c \
				env/env_utils.c \
				env/env_init.c \
				lexer/detect_char_type.c \
				utils/detect_type.c \
				utils/ft_strndup.c \


# ==================== OBJECTS ====================
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# ==================== COMPILATION ====================
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
INCLUDES	= -I$(INCLUDE_DIR) -I$(LIBFT_DIR)
READLINE	= -lreadline

# ==================== RULES ====================

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft $(READLINE) -o $@
	@echo "$(GREEN)$(BOLD)✓ Minishell compiled successfully!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(BLUE)Compiling:$(RESET) $<"

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo "$(YELLOW)Object files cleaned.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(RED)Executable and library cleaned.$(RESET)"

re: fclean all

# ==================== BONUS (if needed later) ====================
bonus:
	@echo "$(YELLOW)No bonus implemented yet.$(RESET)"

.PHONY: all clean fclean re bonus