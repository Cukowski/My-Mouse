TARGET = my_mouse
SRCS = main.c find_shortest_path.c check_maze.c validate.c solve_mark.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f c_files/*.o

fclean: clean
	rm -f $(TARGET) $(OBJS)

re: fclean all