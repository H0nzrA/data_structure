# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/16 15:53:42 by trakotoz          #+#    #+#              #
#    Updated: 2026/10/17 13:35:36 by trakotoz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libds.a
AR		:= ar rcs
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror -g

SRC_DIR		:= src
INC_DIR 	:= inc
OBJ_DIR		:= obj
BUILD_DIR	:= build

FILES	:= memory \
		   heapq heapq_relation heapq_operation \
		   list list_operation


SRCS	:= $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(FILES)))
OBJS	:= $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(FILES)))


MKDIR	:= mkdir -p
RM		:= rm -rf


.PHONY	:= all clean fclean re


all				: $(NAME)

$(NAME)			: $(OBJS) | $(BUILD_DIR)
	$(AR) $(BUILD_DIR)/$@ $^

$(OBJ_DIR)/%.o	: $(SRC_DIR)/%.c $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR)		:
	@ $(MKDIR) $@

$(BUILD_DIR)	:
	@ $(MKDIR) $@

clean			:
	@ $(RM) $(OBJS)

fclean			: clean
	@ $(RM) $(NAME)
	@ $(RM) $(OBJ_DIR) $(BUILD_DIR)

re				: fclean all
