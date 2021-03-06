NAME = libftprintf.a
HEADER =./includes/
FLAG = -Wall -Wextra -Werror -c
OPTION = -I./includes
PATH_SRC = ./srcs/
LIBFT_SRC = ./libft/srcs/

SRC = $(PATH_SRC)ft_handle_base.c $(PATH_SRC)ft_handle_chars.c \
$(PATH_SRC)ft_handle_len.c $(PATH_SRC)ft_handle_num.c \
$(PATH_SRC)ft_misc_1.c $(PATH_SRC)ft_misc_2.c \
$(PATH_SRC)ft_pointers.c $(PATH_SRC)ft_printf.c \

SRC += $(LIBFT_SRC)ft_memset.c $(LIBFT_SRC)ft_strcpy.c $(LIBFT_SRC)ft_bzero.c \
 $(LIBFT_SRC)ft_memmove.c $(LIBFT_SRC)ft_memchr.c $(LIBFT_SRC)ft_memcmp.c \
 $(LIBFT_SRC)ft_strlen.c  $(LIBFT_SRC)ft_strdup.c $(LIBFT_SRC)ft_strncpy.c \
 $(LIBFT_SRC)ft_strcat.c $(LIBFT_SRC)ft_strncat.c $(LIBFT_SRC)ft_strlcat.c \
 $(LIBFT_SRC)ft_strchr.c $(LIBFT_SRC)ft_strstr.c $(LIBFT_SRC)ft_strnstr.c \
 $(LIBFT_SRC)ft_strcmp.c $(LIBFT_SRC)ft_strncmp.c $(LIBFT_SRC)ft_isalpha.c \
 $(LIBFT_SRC)ft_isdigit.c $(LIBFT_SRC)ft_isalnum.c $(LIBFT_SRC)ft_isprint.c \
 $(LIBFT_SRC)ft_toupper.c $(LIBFT_SRC)ft_tolower.c $(LIBFT_SRC)ft_isascii.c \
 $(LIBFT_SRC)ft_memalloc.c $(LIBFT_SRC)ft_memdel.c $(LIBFT_SRC)ft_strnew.c \
 $(LIBFT_SRC)ft_strdel.c $(LIBFT_SRC)ft_strclr.c $(LIBFT_SRC)ft_striter.c \
 $(LIBFT_SRC)ft_striteri.c $(LIBFT_SRC)ft_strmap.c $(LIBFT_SRC)ft_atoi.c \
 $(LIBFT_SRC)ft_memccpy.c $(LIBFT_SRC)ft_memcpy.c $(LIBFT_SRC)ft_putchar.c \
 $(LIBFT_SRC)ft_putchar_fd.c $(LIBFT_SRC)ft_putendl.c \
 $(LIBFT_SRC)ft_putendl_fd.c $(LIBFT_SRC)ft_putstr.c $(LIBFT_SRC)ft_putstr_fd.c \
 $(LIBFT_SRC)ft_putnbr_fd.c $(LIBFT_SRC)ft_putstr.c $(LIBFT_SRC)ft_putstr_fd.c \
 $(LIBFT_SRC)ft_strequ.c $(LIBFT_SRC)ft_strjoin.c $(LIBFT_SRC)ft_strmapi.c \
 $(LIBFT_SRC)ft_strnequ.c $(LIBFT_SRC)ft_strrchr.c $(LIBFT_SRC)ft_strsub.c \
 $(LIBFT_SRC)ft_strtrim.c $(LIBFT_SRC)ft_lstadd.c $(LIBFT_SRC)ft_lstdel.c \
 $(LIBFT_SRC)ft_lstdelone.c $(LIBFT_SRC)ft_lstnew.c $(LIBFT_SRC)ft_lstiter.c \
 $(LIBFT_SRC)ft_lstmap.c $(LIBFT_SRC)ft_strsplit.c $(LIBFT_SRC)ft_itoa.c \
 $(LIBFT_SRC)ft_strrev.c


OBJ = ft_handle_base.o ft_handle_chars.o \
ft_handle_len.o ft_handle_num.o ft_misc_1.o \
ft_misc_2.o ft_pointers.o ft_printf.o \
 ft_memset.o ft_strcpy.o ft_bzero.o \
 ft_memmove.o ft_memchr.o ft_memcmp.o \
 ft_strlen.o  ft_strdup.o ft_strncpy.o \
 ft_strcat.o ft_strncat.o ft_strlcat.o \
 ft_strchr.o ft_strstr.o ft_strnstr.o \
 ft_strcmp.o ft_strncmp.o ft_isalpha.o \
 ft_isdigit.o ft_isalnum.o ft_isprint.o \
 ft_toupper.o ft_tolower.o ft_isascii.o \
 ft_memalloc.o ft_memdel.o ft_strnew.o \
 ft_strdel.o ft_strclr.o ft_striter.o \
 ft_striteri.o ft_strmap.o ft_atoi.o \
 ft_memccpy.o ft_memcpy.o ft_putchar.o \
 ft_putchar_fd.o ft_putendl.o \
 ft_putendl_fd.o ft_putstr.o ft_putstr_fd.o \
 ft_putnbr_fd.o ft_itoa.o ft_strrev.o\
 ft_strequ.o ft_strjoin.o ft_strmapi.o \
 ft_strnequ.o ft_strrchr.o ft_strsub.o \
 ft_strtrim.o ft_lstadd.o ft_lstdel.o \
 ft_lstdelone.o ft_lstnew.o ft_lstiter.o \
 ft_lstmap.o ft_strsplit.o

all: $(NAME)
    
$(NAME):
	@gcc $(FLAG) $(OPTION) $(SRC)
	@ar rc $(NAME) $(OBJ) 
	@ranlib $(NAME)
	@echo "\033[32mBuilt ft_printf library.\033[0m"
	@mkdir ./obj 
	@mv $(OBJ) ./obj/
clean:
	@/bin/rm -rf ./obj
	@echo "\033[32mCleaned up object files.\033[0m"
fclean: clean
		@/bin/rm -f $(NAME)
		@echo "\033[32mCleaned up compiled files.\033[0m"
re: fclean all

