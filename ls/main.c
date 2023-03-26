#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
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
	struct stat buffer;
	int i = 0, x = 0, nb = argc;

	if (argc < 2)
		argv[1] = "./";
	for (i = 1; i < argc; i++)
	{
		if (argv[i][0] == '-' && argv[i][1] == '1')
		{
			x = 1;
			nb -= 1;
		}
	}
	for (i = 1; i < argc; i++)
	{
		if (argv[i][0] == '-')
			continue;
		dir = opendir(argv[i]);
		if (dir)
		{
			if (nb > 2)
				printf("%s:\n", argv[i]);
			while ((read = readdir(dir)) != NULL)
			{
				if (read->d_name[0] != '.' && x == 1)
					printf("%s\n", read->d_name);
				else if (read->d_name[0] != '.' )
					printf("%s  ", read->d_name);
			}
			if (x == 0)
				printf("\n");
			closedir(dir);
		}
		else if (lstat(argv[i], &buffer) == 0)
		{
			if (errno == 13)
			{
				fprintf(stderr, "%s: cannot open directory %s: ", argv[0], argv[i]);
				perror("");
				if (i < argc - 1)
					printf("\n");
				continue;
			}
			printf("%s\n", argv[i]);
		}
		else
		{
			fprintf(stderr, "%s: cannot access %s: ", argv[0], argv[i]);
			perror("");
		}
		if (i < nb - 1)
			printf("\n");
	}
	return (0);
}
