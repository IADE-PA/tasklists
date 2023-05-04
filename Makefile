CFLAGS = -Wall -Wextra -Werror -g
CC = gcc

bin/main: main.c controllers/task_list.c models/tasks.c views/cli.c
	mkdir -p bin
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm bin/*
