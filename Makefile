# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/25 17:51:41 by trakotoz          #+#    #+#              #
#    Updated: 2026/10/25 18:17:11 by trakotoz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB				:= libds.a

DS_DIR			:= lib
DS_BUILD_DIR	:= $(DS_DIR)/build

INCLUDES	:= includes

CC			:= cc
CFlAGS		:= -Wall -Wextra -Werror -g
LIBFLAGS	:= -L. -lds

TEST_DIR	:= tests
TEST_FILE	:= $(TEST_DIR)/main_test.c

all		:
	@ $(MAKE) -C $(DS_DIR)
	@ mv $(DS_BUILD_DIR)/$(LIB) .


clean	:
	@ $(MAKE) clean -C $(DS_DIR)


fclean	:
	@ $(MAKE) fclean -C $(DS_DIR)


re		: fclean all


test	: all
	$(CC) $(CFlAGS) $(TEST_FILE) -I$(INCLUDES) $(LIBFLAGS) -o test
