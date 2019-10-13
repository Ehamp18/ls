# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/19 21:34:35 by elhampto          #+#    #+#              #
#    Updated: 2019/10/04 04:03:29 by elhampto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CODE = print \
		flags \
		split \
		main \
		lr \
		ft_ls \

BTREE = btree_create \
		btree_insert \

INC = -I inclu -I libft/includes

VPATH = code:btree

OBJ_DIR = obj

OBJ  = $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(CODE)))
OBJ += $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(BTREE)))

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g $(INC)

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@echo "\033[31mCreating objects && folder...\033[0m"
	@make -C libft
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "\033[33mMaking libft...\033[0m"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L libft/ -lft

clean:
	@echo "\033[36mCleaning objects...\033[0m"
	@make clean -C libft
	@/bin/rm -rf $(OBJ)

fclean: clean
	@echo "\033[32mCleaning objects and library...\033[0m"
	@make fclean -C libft
	@/bin/rm -rf $(OBJ_DIR)
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
