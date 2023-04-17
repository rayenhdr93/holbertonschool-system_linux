#include "_getline.h"
/**
* _getline - getline
* @fd: file descriptor
* Return: line
*/
char *_getline(const int fd)
{
	char *line = NULL;
	char buffer[READ_SIZE];
	int i = 0;
	ssize_t n;

	while ((n = read(fd, buffer + i, 1)) > 0)
	{
		if (buffer[i] == '\n')
		{
			break;
		}
		i++;
		if (i >= READ_SIZE)
		{
			line = realloc(line, READ_SIZE * sizeof(char));
			if (!line)
			{
				return(NULL);
			}
		}
	}
	if (n == 0)
		exit(0);
	if (n < 0)
	{
		return(NULL);
	}
	if (i >= 0)
	{
		line = malloc((i + 1) * sizeof(char));
		if (!line)
		{
			return(NULL);
		}
		strncpy(line, buffer, i);
		line[i] = '\0';
	}

	return (line);
}
