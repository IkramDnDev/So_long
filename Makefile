# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 14:48:48 by idahhan           #+#    #+#              #
#    Updated: 2025/02/25 17:07:08 by idahhan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror 

SRCS = so_long.c parcing.c get_next_line.c
OBJS = $(SRCS:%.c=%.o)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

HEADER = so_long.h

all : $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJS): %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(LIBFT): $(LIBFT_DIR)/*.c
	@make -C $(LIBFT_DIR)

clean:
	rm -f *.o
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean
