
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <limits.h>
#include <strings.h>

#define MASK 15
//#define FIRST_HASH 61440
//#define SECOND_HASH 3840
//#define THIRD_HASH 240

#include "fillit.h"
void	error(char c)
{
	printf("error on %c\n", c);
	exit(-1);
}

int		fillit(void)
{
	unsigned int tet[26];
	short tetcount;
	int i;
	int fd;
	char buffer[21];
	int hash;
	ssize_t ret;

	i = 0;
	tetcount = 0;
	hash = 0;
	fd = open("/Users/lgutter/test/testbitwise/map.fillit", O_RDONLY);
	printf("fd is %i\nInput file:\n", fd);
	ret = read(fd, buffer, 20);
	while (tetcount != 26 && ret != 0)
	{
		tet[tetcount] = 0;
		buffer[20] = '\0';
		printf("%s\n", buffer);
		while (buffer[i] != '\0')
		{
			while (buffer[i] == '.')
				i++;
			if (buffer[i] == '#')
			{
				hash++;
				tet[tetcount] = tet[tetcount] << 4;
				tet[tetcount] = tet[tetcount] | (i - ((i + 1) / 5));
			}
			else if ((i + 1) % 5 != 0 ||
					 ((i + 1) % 5 == 0 && buffer[i] != '\n'))
				error(buffer[i]);
			i++;
		}
		shift_corner(&tet[tetcount]);
		if (check_tet(tet[tetcount]) != 1)
			error('C');
		i = 0;
		tetcount++;
		if (hash != 4)
			error('H');
		hash = 0;
		if (read(fd, buffer, 1) == 1)
		{
			if (buffer[0] != '\n')
				error('N');
			ret = read(fd, buffer, 20);
			if (ret != 20)
				error('E');
		}
		else
			ret = 0;
	}
	close(fd);
	fd = tetcount - 1;
	tetcount--;
	printf("tets are:\n");
	while (tetcount >= 0)
	{
		printf("%i\n", tet[tetcount]);
		tetcount--;
	}
	tetcount = fd;
	while (tetcount >= 0)
	{
		i = 0;
		fd = 12;
		while (i < 20)
		{
			if (i - ((i + 1) / 5) == ((tet[tetcount] >> fd) & MASK))
			{
				fd -= 4;
				write(1, "#", 1);
			}
			else if ((i + 1) % 5 == 0)
				write(1, "\n", 1);
			else
				write(1, ".", 1);
			i++;
		}
		write(1, "\n", 1);
		tetcount--;
	}
	return (0);
}

int		main(void)
{
	int i;

	i = 0;
	while (i < 1)
	{
		fillit();
		i++;
	}
	return (0);
}
