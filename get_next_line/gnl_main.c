#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	*ret;
	int		fd;
	int		fd_in;

	if (argc != 2)
		return (2);
	fd = open(argv[1], O_RDONLY);
	ret = get_next_line(fd);
	printf("%s", ret);
	while (ret)
	{
		ret = get_next_line(fd);
		if (ret == NULL)
		{
			printf("ret == NULL\n");
		}
		else
			printf("%s", ret);
	}
	close(fd);
}