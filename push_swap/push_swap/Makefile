# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrol-ca <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/19 22:09:17 by jbrol-ca          #+#    #+#              #
#    Updated: 2024/12/19 22:11:36 by jbrol-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Standard
NAME				= push_swap

# Directories
LIBFT				= ./libft/libft.a
INC					= inc/
SRC_DIR				= srcs/
OBJ_DIR				= obj/

# Compiler and CFlags
CC					= cc
CFLAGS				= -Wall -Werror -Wextra -I
RM					= rm -f

# Source Files
COMMANDS_DIR		=	$(SRC_DIR)commands/push.c \
						$(SRC_DIR)commands/rev_rot.c \
						$(SRC_DIR)commands/rot.c \
						$(SRC_DIR)commands/stack_sorting.c \
						$(SRC_DIR)commands/sort_three.c \
						$(SRC_DIR)commands/min_on_top.c \
						$(SRC_DIR)commands/swaps.c

PUSH_SWAP_DIR		=	$(SRC_DIR)push_swap/errors.c \
						$(SRC_DIR)push_swap/pre_errors.c \
						$(SRC_DIR)push_swap/init_stack.c \
						$(SRC_DIR)push_swap/stack_b_to_a.c \
						$(SRC_DIR)push_swap/main.c \
						$(SRC_DIR)push_swap/split.c \
						$(SRC_DIR)push_swap/stack_a_to_b.c \
						$(SRC_DIR)push_swap/helpers_stack.c

# Concatenate all source files
SRCS 				= $(COMMANDS_DIR) $(PUSH_SWAP_DIR)

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build rules
start:
					@make all

$(LIBFT):
					@make -C ./libft

all: 				$(NAME)

$(NAME): 			$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)

# Compile object files from source files
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)

re: 				fclean all

# Phony targets represent actions not files
.PHONY: 			start all clean fclean re
