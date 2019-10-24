# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ifran <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/24 16:10:58 by ifran             #+#    #+#              #
#    Updated: 2019/10/24 16:13:59 by ifran            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCDIR = srcs/
OBJDIR = objs/

SRCS = $(addprefix $(SRCDIR), $(ALL_EX))
ALL_OBJ = $(ALL_EX:%.c=%.o)
OBJS = $(addprefix $(OBJDIR), $(ALL_OBJ))

NAME1 = checker 
NAME2 = push_swap 

INCLUDES_1 = ./includes/checker.h ./libft/includes/libft.h
INCLUDES_2 = ./includes/push_swap.h ./libft/includes/libft.h
COMP_LIB = make -C libft/
FLAGS = -Wall -Wextra -Werror

all: lib $(NAME1) $(NAME2)

$(NAME): ./libft/libft.a $(OBJS)
	@gcc $(FLAGS) -o $(NAME) $(OBJS) -L./libft -lft

$(OBJDIR)%.o: $(SRCDIR)%.c $(INCLUDES)
	@/bin/mkdir -p $(OBJDIR)
	@gcc $(FLAGS) -I./includes -I./libft/includes -c $< -o $@

	lib:
	        @$(COMP_LIB)
./libft/libft.a: lib
	clean:
	        @/bin/rm -rf $(OBJDIR)
			        @$(COMP_LIB) clean
fclean: clean
	@/bin/rm -rf $(NAME)
	@$(COMP_LIB) fclean
re: fclean al

.PHONY: lib clean fclean all re

