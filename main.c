#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int	main(void)
{
	int		fd = open("test.txt", O_RDONLY);
	char	*test =	get_next_line(fd);

	printf("%s\n", test);
	free(test);
	close(fd);
	return (0);
}
