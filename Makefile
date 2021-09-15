# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/27 02:44:28 by acrucesp          #+#    #+#              #
#    Updated: 2021/09/15 19:59:39 by acrucesp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

D	 				=

SRC_DIR				=	src/
SRC					=	

OBJ_DIR				=	obj/
OBJ					= 	$(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))

INC_DIR				=	inc/
HEADER				= 	inc/.h

NAME				=	push_swap	

CC					=	gcc	

RM					= 	rm -f

S					=	-fsanitize=address

OPTIMIZED			=	-O3	

CFLAGS				= 	-Wall -Wextra -Werror $(OPTIMIZED) $(D)

UNAME_S := $(shell uname -s)

all:				$(NAME)

bonus:				all

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -I Libft/inc/ -c $< -o $@ 

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME):	libmlx.a Libft/libft.a $(OBJ) 
	$(CC) $(CFLAGS) -I Libft/inc/ -I inc/ $(MAIN) $(OBJ) Libft/libft.a -o $@ 

Libft/libft.a: 		 
	$(MAKE) -C Libft

libmlx.a:
	$(MAKE) -C mlx_mac 
	cp mlx_mac/libmlx.a ./

.PHONY:				all clean fclean re bonus

clean:
	$(RM) -rf $(OBJ_DIR) $(OBJ_BONUS_DIR)
	$(MAKE) -C Libft clean
	$(RM) -rf libmlx.a

fclean:				clean
	$(RM) $(NAME)
	$(MAKE) -C Libft fclean

re:					fclean all
