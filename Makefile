SRC_PATH = ./src
OBJ_PATH = ./obj
LIB_PATH = ./lib
INC_PATH = -I ./include

CC = gcc
FLAGS = -Wall -Wextra -Werror -g
LIB_NAME = libcomputor.a
MAIN = main.c
EXEC = computor

MAIN_O = $(MAIN:.c=.o)
LIB = $(LIB_PATH)/$(LIB_NAME)
SRC = $(notdir $(wildcard ./src/*.c))
OBJ=$(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))

all: $(MAIN_O) $(OBJ) $(LIB) $(EXEC)

clean:
	@rm -f $(OBJ_PATH)/*.o
	@rm -f $(MAIN_O)

fclean: clean
	@rm -f $(LIB_PATH)/*.a
	@rm -f $(EXEC)

re: fclean all

$(MAIN_O): $(MAIN)
	@$(CC) $(FLAGS) $(INC_PATH) -c $< -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(FLAGS) -c $< -o $@  		

$(LIB_PATH)/%.a:
	@mkdir -p $(LIB_PATH)
	@ar rcs $(LIB) $(OBJ) 

$(EXEC): $(MAIN_O)
	@$(CC) $< $(LIB) -o $@
