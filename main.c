#include "get_next_line.h"

int main(void)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open("test1.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%d: %s\n", i, line);
		free(line);
		i++;
	}
	return (0);
}
