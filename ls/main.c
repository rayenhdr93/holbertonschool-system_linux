#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
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

	if (argc < 2)
		argv[1] = "./";
	dir = opendir(argv[1]);
	while ((read = readdir(dir)) != NULL)
	{
		if (read->d_name[0] != '.')
			printf("%s  ", read->d_name);
	}
	printf("\n");
	closedir(dir);
	return (0);
}
