#include "_getline.h"
/**
* _getline - getline
* @fd: file descriptor
* Return: line
*/
char *_getline(const int fd)
{
	char *line = NULL;
	char buffer[BUFFER_SIZE];
	int i = 0;
	ssize_t n;

	while ((n = read(fd, buffer + i, 1)) > 0)
	{
		if (buffer[i] == '\n')
		{
			break;
		}
		i++;
		if (i >= BUFFER_SIZE)
		{
			line = realloc(line, BUFFER_SIZE * sizeof(char));
			if (!line)
			{
				perror("realloc");
				exit(1);
			}
		}
	}
	if (n == 0)
		exit(0);
	if (n < 0)
	{
		perror("read");
		exit(1);
	}
	if (i >= 0)
	{
		line = malloc((i + 1) * sizeof(char));
		if (!line)
		{
			perror("malloc");
			exit(1);
		}
		strncpy(line, buffer, i);
		line[i] = '\0';
	}

	return (line);
}
