NAME=get_next_line
SRCS=get_next_line.c get_next_line_utils.c

run:
	gcc main.c $(SRCS) -o $(NAME)
	./$(NAME)
