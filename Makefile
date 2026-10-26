LIB				:= libds.a
DS_DIR			:= lib

INCLUDES	:= includes

CC			:= cc
CFlAGS		:= -Wall -Wextra -Werror -g
LIBFLAGS	:= -L. -lds

TEST_DIR	:= tests
TEST_FILE	:= $(TEST_DIR)/main_test.c
TEST_OUT	:= test.out

all		: $(LIB)

$(LIB)	:
	@ $(MAKE) -C $(DS_DIR)
	@ cp $(DS_DIR)/$(LIB) .

clean	:
	@ $(MAKE) clean -C $(DS_DIR)


fclean	:
	@ $(MAKE) fclean -C $(DS_DIR)
	@ rm -f $(LIB) $(TEST_OUT)


re		: fclean all


test	: all
	$(CC) $(CFlAGS) $(TEST_FILE) -I$(INCLUDES) $(LIBFLAGS) -o $(TEST_OUT)
