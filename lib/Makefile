# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/16 15:53:42 by trakotoz          #+#    #+#              #
#    Updated: 2026/11/06 19:37:29 by trakotoz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libds.a
SHARED_NAME	:= libds.so

AR		:= ar
CC		:= cc

ARFLAGS		:= rcs
CFLAGS		:= -Wall -Wextra -Werror -MMD -MP
PICFLAGS	:= -fPIC
SFLAGS		:= -shared

# Color
C_RESET		:= \033[0m
C_GREEN		:= \033[032m
C_BLUE		:= \033[034m
C_MAGENTA	:= \033[035m

SRC_DIR			:= src
INC_DIR 		:= inc
OBJ_DIR			:= obj
SHARED_OBJ_DIR	:= shared_obj

FILES	:= memory \
		   heapq heapq_relation heapq_operation \
		   list list_operation \
		   stack stack_operation \
		   queue queue_memory


SRCS		:= $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(FILES)))
OBJS		:= $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(FILES)))
SHARED_OBJS	:= $(addprefix $(SHARED_OBJ_DIR)/, $(addsuffix .o, $(FILES)))


MKDIR	:= mkdir -p
RM		:= rm -rf


.PHONY	:= all clean fclean re


all				: static shared


# --- Static library
static			: $(NAME)

$(NAME)			: $(OBJS)
	@ echo "$(C_BLUE)> [Buiding] static archive ...$(C_RESET)"
	@ $(AR) $(ARFLAGS) $@ $^
	@ echo "$(C_GREEN)> Static library built: $(C_BLUE)$@$(C_RESET)"

$(OBJ_DIR)/%.o	: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@ echo "$(C_BLUE)> [Compile]$(C_MAGENTA) $< ...$(C_RESET)"
	@ $(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR)		:
	@ $(MKDIR) $@
# ------------------


# --- Shared library
shared					: $(SHARED_NAME)

$(SHARED_NAME)			: $(SHARED_OBJS)
	@ echo "$(C_BLUE)> [Buiding] shared library...$(C_RESET)"
	@ $(CC)  $(SFLAGS) $^ -o $@
	@ echo "$(C_GREEN)> Shared library built: $(C_BLUE)$@$(C_RESET)"

$(SHARED_OBJ_DIR)/%.o	: $(SRC_DIR)/%.c | $(SHARED_OBJ_DIR)
	@ echo "$(C_BLUE)> [Compile]$(C_MAGENTA) $< ...$(C_RESET)"
	@ $(CC) $(CFLAGS) $(PICFLAGS) -I$(INC_DIR) -c $< -o $@

$(SHARED_OBJ_DIR)		:
	@ $(MKDIR) $@
# ------------------


# ---- Cleaning
clean			:
	@ echo "$(C_MAGENTA)> Remove object files ...$(C_RESET)"
	@ $(RM) $(OBJ_DIR) $(SHARED_OBJ_DIR)

fclean			: clean
	@ echo "$(C_MAGENTA)> Remove all generated files ...$(C_RESET)"
	@ $(RM) $(NAME) $(SHARED_NAME)

re				: fclean all
