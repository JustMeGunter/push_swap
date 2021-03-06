# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/27 02:44:28 by acrucesp          #+#    #+#              #
#    Updated: 2021/11/16 18:36:58 by acrucesp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

D	 				=	-g

SRC_DIR				=	src/
SRC					=	main.c parse_args.c init_stack.c ft_swapnode.c\
						ft_pushnode.c ft_rotatenode.c  ft_rrotatenode.c\
					   	select_resolution.c	ft_stackadd_node.c algorithm_three.c\
						ft_order_array.c algorithm_two.c algorithm_four.c\
						cases_algorithm_four.c ft_newstack.c ft_stackadd_front.c\
						ft_stackdel.c algorithm_five.c algorithm_large.c\
						order_array_inverted.c

OBJ_DIR				=	obj/
OBJ					= 	$(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))

INC_DIR				=	inc/
HEADER				= 	pushswap.h

NAME				=	push_swap	

CC					=	gcc	

RM					= 	rm -f

S					=	-fsanitize=address

OPTIMIZED			=	-O3	

CFLAGS				= 	-Wall -Wextra -Werror 

all:				$(NAME)

bonus:				all

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(D) -I $(INC_DIR) -I Libft/inc/ -c $< -o $@ 

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME):	 		Libft/libft.a $(OBJ) 
	$(CC) $(CFLAGS) -I Libft/inc/ -I inc/ $(MAIN) $(OBJ) Libft/libft.a -o $@ 

sanitize:	 		Libft/libft.a $(OBJ) 
	$(CC) $(CFLAGS) $(S) $(D) -I Libft/inc/ -I inc/ $(MAIN) $(OBJ) Libft/libft.a -o $@ 

debug:	 		Libft/libft.a $(OBJ) 
	$(CC) $(CFLAGS) $(D) -I Libft/inc/ -I inc/ $(MAIN) $(OBJ) Libft/libft.a -o $@ 

Libft/libft.a: 		 
	$(MAKE) -C Libft

.PHONY:				all clean fclean re bonus

clean:
	$(RM) -rf $(OBJ_DIR) 
	$(MAKE) -C Libft clean
	$(RM) -rf libmlx.a
	$(RM) -rf sanitize
	$(RM) -rf debug 

fclean:				clean
	$(RM) $(NAME)
	$(MAKE) -C Libft fclean

re:					fclean all

