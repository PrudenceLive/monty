CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
SRC_FILES = monty.c execute_script.c stack_push.c stack_pall.c \
            stack_pint.c stack_pop.c stack_swap.c stack_add.c \
            stack_nop.c stack_sub.c stack_div.c stack_mul.c \
            stack_mod.c stack_pchar.c stack_pstr.c stack_rotl.c \
            stack_rotr.c op_stack.c op_queue.c free_all.c isNum.c

OBJ_FILES = $(SRC_FILES:.c=.o)
EXECUTABLE = monty

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(EXECUTABLE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(EXECUTABLE)

re: fclean all
