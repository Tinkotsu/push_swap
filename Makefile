# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ifran <ifran@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/24 16:10:58 by ifran             #+#    #+#              #
#    Updated: 2019/11/07 18:42:50 by ifran            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSH_SWAP = push_swap

CH_SRC = ch_main.c checker.c

PS_SRC = ps_do_op.c ps_find_ops.c ps_find_values.c ps_index.c \
		 ps_leave_three.c ps_main.c ps_stack_len.c push_swap.c

CM_SRC = cm_all_free.c cm_error.c cm_is_sorted.c cm_push.c \
		 cm_reverse_rotate.c cm_rotate.c cm_swap.c cm_test.c \
		 cm_validate_and_push.c

SRCDIR = srcs/
OBJDIR = objs/

CH_SRCS = $(addprefix $(SRCDIR), $(CH_SRC))
PS_SRCS = $(addprefix $(SRCDIR), $(PS_SRC))
CM_SRCS = $(addprefix $(SRCDIR), $(CM_SRC))

CH_OBJ = $(CH_SRC:%.c=%.o)
PS_OBJ = $(PS_SRC:%.c=%.o)
CM_OBJ = $(CM_SRC:%.c=%.o)

CH_OBJS = $(addprefix $(OBJDIR), $(CH_OBJ))
PS_OBJS = $(addprefix $(OBJDIR), $(PS_OBJ))
CM_OBJS = $(addprefix $(OBJDIR), $(CM_OBJ))

CH_HEADER = ./includes/checker.h 
PS_HEADER = ./includes/push_swap.h
CM_HEADER = ./includes/common.h
LIB_HEADER = ./libft/includes/libft.h

COMP_LIB = make -C libft/
FLAGS = -Wall -Wextra -Werror

all: lib ./libft/libft.a $(CHECKER) $(PUSH_SWAP)

$(CHECKER): $(CM_OBJS) $(CH_OBJS) $(CH_HEADER) $(CM_HEADER) $(LIB_HEADER)
	@gcc $(FLAGS) -L libft -lft -o $(CHECKER) $(CH_OBJS) $(CM_OBJS)

$(PUSH_SWAP): $(CM_OBJS) $(PS_OBJS) $(PS_HEADER) $(CM_HEADER) $(LIB_HEADER)
	@gcc $(FLAGS) -L libft -lft -o $(PUSH_SWAP) $(PS_OBJS) $(CM_OBJS)

$(OBJDIR)cm_%.o: $(SRCDIR)cm_%.c $(CM_HEADER)
	@/bin/mkdir -p $(OBJDIR)
	@gcc $(FLAGS) -I./includes -I./libft/includes -c $< -o $@

$(OBJDIR)ch%.o: $(SRCDIR)ch%.c $(CH_HEADER)
	@gcc $(FLAGS) -I./includes -I./libft/includes -c $< -o $@

$(OBJDIR)p%.o: $(SRCDIR)p%.c $(PS_HEADER)
	@gcc $(FLAGS) -I./includes -I./libft/includes -c $< -o $@

lib:
	@$(COMP_LIB)

clean:
	@/bin/rm -rf $(OBJDIR)
	@$(COMP_LIB) clean

fclean: clean
	@/bin/rm -rf $(CHECKER)
	@/bin/rm -rf $(PUSH_SWAP)
	@$(COMP_LIB) fclean

re: fclean all

.PHONY: lib clean fclean all re
