LIB_STATIC		:= libds.a
LIB_SHARED		:= libds.so
DS_DIR			:= lib

INCLUDES	:= includes

CC			:= cc
CFlAGS		:= -Wall -Wextra -Werror -g
LIBFLAGS	:= -L. -lds

TEST_DIR	:= tests
TEST_FILE	:= $(TEST_DIR)/main_test.c
TEST_OUT	:= test.out

all		: static shared

static	:
	@ $(MAKE) $@ -C $(DS_DIR)
	@ cp $(DS_DIR)/$(LIB_STATIC) .

shared	:
	@ $(MAKE) $@ -C $(DS_DIR)
	@ cp $(DS_DIR)/$(LIB_SHARED) .

$(LIB)	:
	@ $(MAKE) -C $(DS_DIR)
	@ cp $(DS_DIR)/$(LIB_STATIC) .
	@ cp $(DS_DIR)/$(LIB_SHARED) .

clean	:
	@ $(MAKE) clean -C $(DS_DIR)


fclean	:
	@ $(MAKE) fclean -C $(DS_DIR)
	@ rm -f $(LIB_STATIC) $(LIB_SHARED) $(TEST_OUT)


re		: fclean all


test	: all
	$(CC) $(CFlAGS) $(TEST_FILE) -I$(INCLUDES) $(LIBFLAGS) -o $(TEST_OUT)
