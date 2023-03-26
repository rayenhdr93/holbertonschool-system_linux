#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>
/**
* main - main func
* @argc: num of argum
* @argv: arguments
* Return: return
*/
int main(int argc, char *argv[])
{
	DIR *dir;
	struct dirent *read;
	int i = 0;

	if (argc < 2)
		argv[1] = "./";
	for (i = argc - 1; i > 0; i--)
	{
		if (argc > 2)
			printf("%s:\n", argv[i]);
		dir = opendir(argv[i]);
		if (dir) 
		{
			while ((read = readdir(dir)) != NULL)
			if (read->d_name[0] != '.')
				printf("%s  ", read->d_name);
			printf("\n");
			closedir(dir);
		} 
		else (ENOENT == errno)
		{
			fprintf(stderr, "./hls: cannot access %s: ", argv[i]);
			perror("");
		}
		if (i > 1)
			printf("\n");
	}
	return (0);
}
