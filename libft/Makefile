# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egerin <egerin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 15:31:52 by egerin            #+#    #+#              #
#    Updated: 2025/11/15 22:11:00 by ehossain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS=-Wall -Wextra -Werror
SRC = ft_isalpha.c ft_isdigit.c ft_strlen.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strncmp.c \
ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
ft_tolower.c ft_strchr.c ft_strrchr.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c \
ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strstr.c\
ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr_base.c \
get_next_line.c get_next_line_utils.c
OBJ = ${SRC:.c=.o}
NAME = libft.a

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo -n "$(GREEN)libft complied"
	@echo -n "$(END)\n"

clean : 
	@rm -f $(OBJ)
	@echo -n "$(RED)libft object files removed"
	@echo -n "$(END)\n"

fclean :
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@echo -n "$(RED)libft object files removed\n"
	@echo -n "$(RED)libft.a removed"
	@echo -n "$(END)\n"

re : fclean all

.PHONY: clean fclean re all

# Define color variables
RED    = \033[0;31m
GREEN  = \033[0;32m
END     = \033[0m
