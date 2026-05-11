NAME = libft.a
CC = cc

HEADER = libft.h\
		ft_printf/ft_printf.h\
		ft_printf_fd/ft_printf_fd.h\
		get_next_line/get_next_line.h\
		get_next_line_bonus/get_next_line_bonus.h\
		get_next_line_fd/get_next_line_fd.h

SRCS_CHARACTER = char/ft_int_len_unsi.c\
		char/ft_int_len.c \
		char/ft_isalnum.c \
		char/ft_isalpha.c \
		char/ft_isascii.c \
		char/ft_isdigit.c \
		char/ft_isprint.c \
		char/ft_issign.c \
		char/ft_isspace.c \
		char/ft_tolower.c \
		char/ft_toupper.c 

SRCS_DICT = dict/ft_dict_clear.c\
		dict/ft_dict_get_node.c \
		dict/ft_dict_get.c \
		dict/ft_dict_new.c \
		dict/ft_dict_set.c \
		dict/ft_dict_unset.c

SRCS_PRINTF = ft_printf/ft_print_char.c\
		ft_printf/ft_print_char_va.c\
		ft_printf/ft_print_dec_va.c\
		ft_printf/ft_print_hex_low.c\
		ft_printf/ft_print_hex_up.c\
		ft_printf/ft_print_hex.c\
		ft_printf/ft_print_int_va.c\
		ft_printf/ft_print_nbr.c\
		ft_printf/ft_print_percent.c\
		ft_printf/ft_print_ptr.c\
		ft_printf/ft_print_ptr_va.c\
		ft_printf/ft_print_str.c\
		ft_printf/ft_print_unsigned.c\
		ft_printf/ft_printf.c \
		ft_printf/ft_printf_va.c \
		ft_printf/ft_print_string.c \
		ft_printf/ft_utils.c

SRCS_PRINTF_FD = ft_printf_fd/ft_printf_fd.c \
		ft_printf_fd/ft_putaddr_fd.c \
		ft_printf_fd/ft_putchar_fd.c \
		ft_printf_fd/ft_putchar_fd2.c \
		ft_printf_fd/ft_putendl_fd.c \
		ft_printf_fd/ft_putnbr_fd.c \
		ft_printf_fd/ft_putnbr_fd2.c \
		ft_printf_fd/ft_putnbrhexa_fd.c \
		ft_printf_fd/ft_putstr_fd.c \
		ft_printf_fd/ft_putstr_fd2.c \
		ft_printf_fd/ft_putunbr_fd.c \
		ft_printf_fd/ft_startwith_fd.c \
		ft_printf_fd/ft_strcmp_fd.c \
		ft_printf_fd/ft_strlen_fd.c

SRCS_GET_NEXT_LINE = get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c

SRCS_GET_NEXT_LINE_BONUS = get_next_line_bonus/get_next_line_bonus.c \
		get_next_line_bonus/get_next_line_utils_bonus.c

SRCS_GET_NEXT_LINE_FD = get_next_line_fd/get_next_line_fd.c \
		get_next_line_fd/get_next_line_utils_fd.c

SRCS_LIST = list/ft_lstadd_back.c \
		list/ft_lstadd_front.c \
		list/ft_lstclear.c \
		list/ft_lstdelone.c \
		list/ft_lstiter.c \
		list/ft_lstlast.c \
		list/ft_lstmap.c \
		list/ft_lstnew.c \
		list/ft_lstsize.c

SRCS_MEMORY = memory/ft_bzero.c \
		memory/ft_calloc.c \
		memory/ft_memchr.c \
		memory/ft_memcmp.c \
		memory/ft_memcpy.c \
		memory/ft_memmove.c \
		memory/ft_memset.c

SRCS_PUT = put_fd/ft_putchar_fdp.c \
		put_fd/ft_putendl_fdp.c \
		put_fd/ft_putnbr_fdp.c \
		put_fd/ft_putstr_fdp.c

SRCS_STRING = string/ft_atoi.c \
		string/ft_atol.c \
		string/ft_endwith.c \
		string/ft_itoa.c\
		string/ft_replace.c\
		string/ft_split.c \
		string/ft_startwith.c \
		string/ft_strchr.c \
		string/ft_strcmp.c \
		string/ft_strdup.c \
		string/ft_striteri.c \
		string/ft_strjoin.c \
		string/ft_strlcat.c \
		string/ft_strlcpy.c \
		string/ft_strlen.c \
		string/ft_strmapi.c \
		string/ft_strncmp.c \
		string/ft_strndup.c \
		string/ft_strndup2.c \
		string/ft_strnstr.c \
		string/ft_strrchr.c \
		string/ft_strtrim.c \
		string/ft_substr.c 

SRCS = $(SRCS_CHARACTER) \
	$(SRCS_STRING) \
	$(SRCS_MEMORY) \
	$(SRCS_PUT) \
	$(SRCS_LIST) \
	$(SRCS_DICT) \
	$(SRCS_PRINTF_FD) \
	$(SRCS_PRINTF) \
	$(SRCS_GET_NEXT_LINE)\
	$(SRCS_GET_NEXT_LINE_FD) \
	$(SRCS_GET_NEXT_LINE_BONUS)

OBJS = $(SRCS:%.c=%.o) 

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g -I ft_printf/ft_printf.h -I ft_printf_fd/ft_printf_fd.h -I get_next_line/get_next_line.h -I get_next_line_bonus/get_next_line_bonus.h -I get_next_line_fd/get_next_line_fd.h -I .

AR = ar -rcs

all: 
	@$(MAKE) $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	@clear
	@echo "\n\033[32m🔥LIBFT OBJS - SUCCESS! 🔥\033[0m\n"

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean all fclean re
