# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/16 15:53:42 by trakotoz          #+#    #+#              #
#    Updated: 2026/10/25 19:37:21 by trakotoz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libds.a
AR		:= ar
CC		:= cc

ARFLAGS	:= rcs
CFLAGS	:= -Wall -Wextra -Werror -g -MMD -MP

# Color
C_RESET		:= \033[0m
C_GREEN		:= \033[032m
C_BLUE		:= \033[034m
C_MAGENTA	:= \033[035m

SRC_DIR		:= src
INC_DIR 	:= inc
OBJ_DIR		:= obj

FILES	:= memory \
		   heapq heapq_relation heapq_operation \
		   list list_operation \
		   stack stack_operation


SRCS	:= $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(FILES)))
OBJS	:= $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(FILES)))


MKDIR	:= mkdir -p
RM		:= rm -rf


.PHONY	:= all clean fclean re


all				: $(NAME)


$(NAME)			: $(OBJS) | $(BUILD_DIR)
	@ echo "$(C_BLUE)> [Buiding] archive ...$(C_RESET)"
	@ $(AR) $(ARFLAGS) $(NAME) $^
	@ echo "$(C_GREEN)> Archive Data Structure build: $(C_BLUE)$(NAME)$(C_RESET)"


$(OBJ_DIR)/%.o	: $(SRC_DIR)/%.c $(OBJ_DIR)
	@ echo "$(C_BLUE)> [Compile]$(C_MAGENTA) $< ...$(C_RESET)"
	@ $(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@


$(OBJ_DIR)		:
	@ $(MKDIR) $@


clean			:
	@ echo "$(C_MAGENTA)> Remove object files ...$(C_RESET)"
	@ $(RM) $(OBJS) $(OBJ_DIR)


fclean			: clean
	@ echo "$(C_MAGENTA)> Remove all generated files ...$(C_RESET)"
	@ $(RM) $(NAME)
	@ $(RM) $(OBJ_DIR) $(BUILD_DIR)


re				: fclean all
