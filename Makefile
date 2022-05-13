man:
	gcc -g -fsanitize=address get_next_line.c get_next_line_utils.c main.c -D BUFFER_SIZE=1
bonus:
	gcc -g -fsanitize=address get_next_line_bonus.c get_next_line_utils_bonus.c main.c -D BUFFER_SIZE=1
	./a.out
