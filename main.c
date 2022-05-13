#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		i;
	int		fd1;
	char	*line;

	// int		fd2;
	// int		fd3;
	// int		fd3;
	i = 0;
	// fd2 = open("text2.txt", O_RDONLY);
	// fd3 = open("text3.txt", O_RDONLY);
	while (1)
	{
		fd1 = open("text1.txt", O_RDONLY);
		printf("%d: %d\n", i, fd1);
		line = get_next_line(fd1);
		if (line == NULL)
			break ;
		// printf("%d: %s", i, line);
		free(line);
		i++;
	}
	return (0);
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q a.out");
// }
