# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ifran <ifran@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/24 16:10:58 by ifran             #+#    #+#              #
#    Updated: 2019/10/24 16:37:04 by ifran            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC1 = ch_*.c
SRC2 = ps_*.c

SRCDIR = srcs/
OBJDIR = objs/

SRCS = $(addprefix $(SRCDIR), $(ALL_EX))
ALL_OBJ = $(ALL_EX:%.c=%.o)
OBJS = $(addprefix $(OBJDIR), $(ALL_OBJ))

NAME1 = checker
NAME2 = push_swap

INCLUDES_1 = ./includes/checker.h 
INCLUDES_2 = ./includes/push_swap.h
INCLUDES_L = ./libft/includes/libft.h

COMP_LIB = make -C libft/
FLAGS = -Wall -Wextra -Werror

all: lib $(NAME1) $(NAME2)

$(NAME1): $(OBJS)
	@gcc $(FLAGS) -o $(NAME1) $(OBJS1) -L./libft -lft

$(OBJDIR1)%.o: $(SRCDIR1)%.c $(INCLUDES1)
	@/bin/mkdir -p $(OBJDIR1)
	@gcc $(FLAGS) -I./includes -I./libft/includes -c $< -o $@

lib:
	@$(COMP_LIB)

clean:
	@/bin/rm -rf $(OBJDIR)
	@$(COMP_LIB) clean

fclean: clean
	@/bin/rm -rf $(NAME)
	@$(COMP_LIB) fclean

re: fclean al

.PHONY: lib clean fclean all re
